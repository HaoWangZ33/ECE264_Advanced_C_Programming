#ifndef PA04_H
#define PA04_H 

typedef struct _charnode {
	struct _charnode *next;
	char ch;
	long int count;
} charnode;



void read_file(long int*, FILE*);
charnode* construct_list(long int*);
charnode* construct_node(int, long int);
charnode* enqueue(charnode **, int, long int);
void charnode_destroy(charnode*);

#endif
