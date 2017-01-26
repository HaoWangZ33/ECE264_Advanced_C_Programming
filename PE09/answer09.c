#include <stdio.h>
#include <stdlib.h>
#include "answer09.h"

lnode* construct_node(void *);

lnode* construct_node(void *new_object) {
   lnode* new_node = malloc(sizeof(*new_node));
   if (new_node == NULL) {
      return NULL;
   }
   new_node->ptr = new_object;
   new_node->next = NULL;
   return new_node;
}

lnode *PQ_enqueue(lnode **pq, const void *new_object, 
                  int (*cmp_fn)(const void *, const void *))
{
   if (new_object == NULL) {
      return NULL;
   }

   lnode* new_node = construct_node((void *)new_object);
   if (new_node == NULL) {
      fprintf(stderr, "malloc fail!\n");
      return NULL;
   }

   lnode dummy;
   dummy.next = *pq;
   lnode* prev = &dummy;
   lnode* curr = *pq;
   while (curr != NULL) {
      if (cmp_fn(new_object, curr->ptr) <= 0) {
         break;
      }
      prev = curr;
      curr = curr->next;
   }
   prev->next = new_node;
   new_node->next = curr;
   *pq = dummy.next;
   return new_node;
}
                       
lnode *PQ_dequeue(lnode **pq)
{
   if (*pq == NULL) {
      return NULL;
   }
   lnode* first_node = *pq;
   *pq = first_node->next;
   first_node->next = NULL;
   return first_node;
}

lnode *stack_push(lnode **stack, const void *new_object)
{
   if (new_object == NULL) {
      return NULL;
   }
   lnode* new_node = construct_node((void *)new_object);
   if (new_node == NULL) {
      fprintf(stderr, "malloc fail!\n");
      return NULL;
   }

   new_node->next = *stack;
   *stack = new_node;
   return new_node;
}
                       
lnode *stack_pop(lnode **stack)
{
   if (*stack == NULL) {
      return NULL;
   }

   lnode* first_node = *stack;
   *stack = (*stack)->next;
   first_node->next = NULL;
   return first_node;
}

lnode *lnode_remove_last(lnode **list)
{
   if (*list == NULL) {
      return NULL;
   }
   lnode dummy;
   dummy.next = *list;
   lnode* prev = &dummy;
   lnode* curr = *list;
   while (curr->next != NULL) {
      prev = curr;
      curr = curr->next;
   }
   prev->next = NULL;
   *list = dummy.next;
   return curr;
}

void lnode_destroy(lnode *list, void (*destroy_fn)(void *))
{
   lnode* temp;
   while (list != NULL) {
      temp = list;
      list = list->next;
      destroy_fn(temp->ptr);
      free(temp);
   }
   return;
}

/* print an entire linked list                                           */
/* pq is the address of the first lnode in the linked list               */
/* print_fn is the address of the function to print the generic object,  */
/* of which the address is stored in the ptr field of an lnode in the    */
/* linked list                                                           */
/*                                                                       */
/* DO NOT CHANGE THIS FUNCTION, OTHERWISE YOUR OUTPUT WILL BE DIFFERENT  */
/* AND YOU WILL NOT RECEIVE CREDIT                                       */
 
void lnode_print(const lnode *list, void (*print_fn)(const void *))
{
   while (list != NULL) {
      // print the memory associated with list->ptr
      print_fn(list->ptr);
      // print an arrow
      fprintf(stdout, "->");
      list = list->next;
   } 
   // print NULL and a newline after that 
   fprintf(stdout, "NULL\n");
}
