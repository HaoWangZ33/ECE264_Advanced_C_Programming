#ifndef PE09_H
#define PE09_H 

/* self-referencing structure for a linked list                    */
/* ptr stores an address pointing to a generic type                */
/* next stores an address pointing to a structure of the same type */
/* so that a list can be formed                                    */

typedef struct _lnode {
   void *ptr;
   struct _lnode *next;
} lnode;

/* the following functions deal with priority queues implemented         */
/* as a linked list of lnode's, with the address of each object of       */
/* interest stored in the ptr field of an lnode in the list              */

/* adding an lnode to a priority queue (PQ) implemented as a linked list */
/* such that linked list is ordered (accordinging to the cmp_fn          */
/* function) from smallest to the largest                                */
/* *pq is the address of the first lnode in the linked list; it is NULL  */
/* if the linked list is empty                                           */
/* new_object is the address of the new object to be stored in the ptr   */
/* field of the new lnode in the linked list pq; if it is NULL, the      */
/* linked list should remain the same                                    */
/* cmp_fn is the address of the function that can compare two objects    */
/* whose addresses are passed to the cmp_fn function;  the two addresses */
/* are typically stored in the ptr fields of two lnodes in the           */
/* linked list; returns a negative number if the first object is smaller,*/
/* a positive number if the first object is bigger, 0 if the two objects */
/* are the same                                                          */
/*                                                                       */
/* *pq should be updated if the new lnode added becomes the first lnode  */
/* of the linked list                                                    */
/* returns the address of the newly added lnode in the linked list       */
/* if you cannot allocate space for the new lnode, keep the linked list  */
/* the same and you should return NULL                                   */
/* if new_object is NULL, you should keep the linked list the same and   */
/* return NULL                                                           */

lnode *PQ_enqueue(lnode **pq, const void *new_object, 
                  int (*cmp_fn)(const void *, const void *));

/* remove the first lnode in a priority queue (PQ) implemented as a      */
/* linked list                                                           */
/* *pq is the address of the first lnode in the linked list; *pq is NULL */
/* if the linked list is empty                                           */
/*                                                                       */
/* if the linked list is empty, returns NULL                             */
/* otherwise, remove the first lnode from the linked list and update *pq */
/* set the removed lnode to be a single-node linked list and return the  */
/* address of the removed lnode                                          */
                       
lnode *PQ_dequeue(lnode **pq);

/* the following functions deal with stacks implemented                  */
/* as a linked list of lnode's, with the address of each object of       */
/* interest stored in the ptr field of an lnode in the list              */

/* adding an lnode to a stack implemented as a linked list               */
/* *stack is the address of the first lnode in the linked list; it is    */
/* NULL if the linked list is empty                                      */
/* new_object is the address of the new object to be stored in the ptr   */
/* field of the new lnode in the linked list pq; if it is NULL, the      */
/* linked list should remain the same                                    */
/*                                                                       */
/* *stack should be updated after adding the new lnode as the first lnode*/
/* of the linked list                                                    */
/* returns the address of the newly added lnode in the linked list       */
/* if you cannot allocate space for the new lnode, keep the linked list  */
/* the same and you should return NULL                                   */
/* if new_object is NULL, you should keep the linked list the same and   */
/* return NULL                                                           */

lnode *stack_push(lnode **stack, const void *new_object);

/* remove the first lnode on a stack implemented as a linked list        */
/* *stack is the address of the first lnode in the linked list; *stack   */
/* is NULL if the linked list is empty                                   */
/*                                                                       */
/* if the linked list is empty, returns NULL                             */
/* otherwise, remove the first lnode from the linked list and update     */
/* *stack                                                                */
/* set the removed lnode to be a single-node linked list and return the  */
/* address of the removed lnode                                          */
                       
lnode *stack_pop(lnode **stack);

/* the following functions deal with linked list                         */
/* some of these functions are already defined in the answer09.c file    */

/* remove the last lnode in a linked list of lnode's                     */
/* *list is the address of the first lnode in the linked list; *list     */
/* is NULL if the linked list is empty                                   */
/*                                                                       */
/* if the linked list is empty, returns NULL                             */
/* otherwise, remove the last lnode from the linked list and update      */
/* *list if necessay                                                     */
/* set the removed lnode to be a single-node linked list and return the  */
/* address of the removed lnode                                          */

lnode *lnode_remove_last(lnode **list);

/* destroy an entire linked list, freeing all memory used                */
/* pq is the address of the first lnode in the linked list               */
/* destroy_fn is the address of the function to free the memory          */
/* associated with the address of the generic object stored in the ptr   */
/* field of lnode in the linked list                                     */
/* if ptr is storing an address of a simple data type, the function free */
/* is an appropriate destroy_fn                                          */
/* if ptr is storing an address of a structure or an array that stores   */
/* other addresses, a user-defined destroy_fn would be required.  For    */
/* example, if ptr stores an address of structure Maze in PE08, you would*/
/* have to use Deallocate_maze_space as the destroy_fn function.         */

void lnode_destroy(lnode *list, void (*destroy_fn)(void *));

/* print an entire linked list                                           */
/* pq is the address of the first lnode in the linked list               */
/* print_fn is the address of the function to print the generic object,  */
/* of which the address is stored in the ptr field of an lnode in the    */
/* linked list                                                           */
 
void lnode_print(const lnode *list, void (*print_fn)(const void *));

/* functions defined by instructors for grading purpose, you should not  */
/* define them                                                           */

lnode *__PQ_enqueue(lnode **pq, const void *new_object, 
                  int (*cmp_fn)(const void *, const void *));

lnode *__PQ_dequeue(lnode **pq);
lnode *__stack_push(lnode **stack, const void *new_object);
lnode *__stack_pop(lnode **stack);
lnode *__lnode_remove_last(lnode **list);
void __lnode_destroy(lnode *list, void (*destroy_fn)(void *));
void __lnode_print(const lnode *list, void (*print_fn)(const void *));

#endif
