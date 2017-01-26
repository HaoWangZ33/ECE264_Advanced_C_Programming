#ifndef PE10_H
#define PE10_H 

typedef struct _charnode {
	struct _charnode *next;
	char ch;
	long int count;
} charnode;

typedef struct _treenode {
	struct _treenode* left;
	struct _treenode* right;
	char ch;
	long int count;
} treenode;

typedef struct _stacknode {
	struct _stacknode* next;
	struct _treenode* tree;
} stacknode;

void read_file(long int*, FILE*);
void print_array(long int*, char*);
charnode* construct_list(long int*);
charnode* construct_node(int, long int);
treenode* construct_treenode(char, long int);
charnode* enqueue(charnode **, int, long int);
void print_list(charnode*, char*);
void print_tree(treenode*, char*);
treenode* construct_tree(charnode**);
stacknode* stack_push(stacknode**, treenode*);
stacknode* stack_pop(stacknode**);
void tree_destroy(treenode*);
void destroy_stack(stacknode*);
void charnode_destroy(charnode*);
void post_order(treenode*, FILE*, long int, long int);

#endif
