#include <stdio.h>
#include <stdlib.h>
#include "answer10.h"

void read_file(long int* array, FILE* infile){
	int ch;
	int i;
	for (i = 0; i < 256; i++) {
		array[i] = 0;
	}
	fseek(infile, 0, SEEK_SET);
	while ((ch = fgetc(infile)) != EOF){
		array[((int)ch)] = array[((int)ch)] + 1;
	}
}

void print_array(long int* array, char* filename) {
	FILE* outfile;
	int count;

	outfile = fopen(filename, "w");
	if (outfile == NULL) {
		fprintf(stderr, "Fail to write to file 1");
		return;
	}

	fseek(outfile, 0, SEEK_SET);
	for(count = 0; count < 256; count++) {
		fprintf(outfile, "%ld\n", array[count]);
	}
	fclose(outfile);
}

void print_list(charnode* head, char* filename) {
	FILE* outfile;
	charnode* curr = head;

	outfile = fopen(filename, "w");
	if (outfile == NULL) {
		fprintf(stderr, "Fail to write to file 2");
		return;
	}
	fseek(outfile, 0, SEEK_SET);

	while (curr != NULL) {
		fprintf(outfile, "%c:%ld->", curr->ch, curr->count);
		curr = curr->next;
	}
	fprintf(outfile, "NULL");
	fclose(outfile);
}

void print_tree(treenode* tree, char* filename) {
	FILE* outfile;
	long int path = 0;
	long int count0 = 0;

	outfile = fopen(filename, "w");
	if (outfile == NULL) {
		fprintf(stderr, "Fail to write to file 3");
		return;
	}
	fseek(outfile, 0, SEEK_SET);
	post_order(tree, outfile, path, count0);
	fclose(outfile);
}

void post_order(treenode* tree, FILE* outfile, long int path, long int count0) {
	if (tree == NULL) {
		return;
	}
	if (tree->ch == '\0') {
		post_order(tree->left, outfile, path*10, (path == 0) ? count0+1:count0);
		post_order(tree->right, outfile, path*10+1, count0);
	}
	fprintf(outfile, "%c:", tree->ch);
	int i = 0;
	for (i = 0; i < count0; i++) {
		fputc(48, outfile);
	}
	fprintf(outfile, "%ld\n", path);
	printf("%c  %ld", tree->ch, path);
}

treenode* construct_tree(charnode** head_add) {
	charnode* head = *head_add;
	charnode* temp = head;
	stacknode* stack = NULL;
	stacknode* pop_stack;
	treenode* tree = NULL;
	treenode* pop_tree = NULL;
	treenode* temp_tree = NULL;

	tree = construct_treenode(head->ch, head->count);
	stack = stack_push(&stack, tree);
	head = head->next;
	temp = head;
	while (head != NULL) {
		tree = construct_treenode(head->ch, head->count);
		if (temp->count < stack->tree->count) {
			stack = stack_push(&stack, tree);
		} else {
			pop_stack = stack_pop(&stack);
			pop_tree = pop_stack->tree;
			free(pop_stack);
			temp_tree = construct_treenode('\0', (pop_tree->count + tree->count));
			temp_tree->left = tree;
			temp_tree->right = pop_tree;
			stack = stack_push(&stack, temp_tree);
		}
		head = head->next;
		temp = head;
	}
	while (stack->next != NULL) {
		stacknode* stack_1 = stack_pop(&stack);
		treenode* tree_1 = stack_1->tree;
		free(stack_1);
		stacknode* stack_2 = stack_pop(&stack);
		treenode* tree_2 = stack_2->tree;
		free(stack_2);
		temp_tree = construct_treenode('\0', (tree_1->count + tree_2->count));
		temp_tree->left = tree_2;
		temp_tree->right = tree_1;
		stack = stack_push(&stack, temp_tree);
	}
	pop_stack = stack_pop(&stack);
	pop_tree =  pop_stack->tree;
	free(pop_stack);
	destroy_stack(stack);
	return pop_tree;
}

stacknode *stack_push(stacknode **stack, treenode* tree) {
	if (tree == NULL) {
		return NULL;
	}
	stacknode* new_node = malloc(sizeof(*new_node));
	if (new_node == NULL) {
		fprintf(stderr, "malloc fail!\n");
		return NULL;
	}
	new_node->tree = tree;
	new_node->next = *stack;
	return new_node;
}
                       
stacknode* stack_pop(stacknode **stack) {
	if (*stack == NULL) {
		return NULL;
	}
	stacknode* first_node = *stack;
	*stack = (*stack)->next;
	first_node->next = NULL;
	return first_node;
}

treenode* construct_treenode(char ch, long int count) {
	treenode* new_node = malloc(sizeof(*new_node));
	if (new_node == NULL) {
		return NULL;
	}
	new_node->ch = ch;
	new_node->count = count;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

charnode* construct_list(long int* array) {
	int count = 0;
	charnode* head = NULL;
	for (count = 0; count < 256; count++) {
		head = enqueue(&head, count, array[count]);
	}
	return head;
}

charnode* construct_node(int ch, long int count) {
	charnode* new_node = malloc(sizeof(*new_node));
	if (new_node == NULL) {
		return NULL;
	}
	new_node->ch = (char)ch;
	new_node->count = count;
	new_node->next = NULL;
	return new_node;
}

charnode* enqueue(charnode **head, int ch, long int count) {
	if (count == 0) {
		return *head;
	}
	charnode* new_node = construct_node(ch, count);
	if (new_node == NULL) {
		fprintf(stderr, "malloc fail!\n");
		return NULL;
	}

	charnode dummy;
	dummy.next = *head;
	charnode* prev = &dummy;
	charnode* curr = *head;
	while (curr != NULL) {
		if (curr->count >= count) {
			break;
		}
		prev = curr;
		curr = curr->next;
	}
	if (curr != NULL) {
		if (curr->count == count) {
			while (curr != NULL) {
				if ((curr->count != count) || ((int)(curr->ch) > ch)) {
					break;
				}
				prev = curr;
				curr = curr->next;
			}
		}
	}
	prev->next = new_node;
	new_node->next = curr;
	*head = dummy.next;
	return *head;
}

void tree_destroy(treenode *root) {
   if (root == NULL) 
      return;
   tree_destroy(root->left);
   tree_destroy(root->right);
   free(root);
}

void charnode_destroy(charnode* head) {
	if (head == NULL) {
		return;
	}
	charnode* temp = head;
	charnode* curr = head;
	curr = curr->next;
	free(temp);
	charnode_destroy(curr);
}

void destroy_stack(stacknode* stack) {
	if (stack == NULL) {
		return;
	}
	stacknode* temp = stack;
	stacknode* curr = stack;
	curr = curr->next;
	free(temp->tree);
	free(temp);
	destroy_stack(curr);
}
