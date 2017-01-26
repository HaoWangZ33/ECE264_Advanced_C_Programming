#include <stdio.h>
#include <stdlib.h>
#include "answer04.h"

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
