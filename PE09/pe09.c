#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer09.h"

int main(int argc, char ** argv)
{
   lnode *head = NULL;

   char *new_string = (char *)malloc(sizeof(char)*(strlen("abcd")+1));
   strcpy(new_string, "abcd");
   lnode *new_node = stack_push(&head, new_string);

   new_string = (char *)malloc(sizeof(char)*(strlen("efgh")+1));
   strcpy(new_string, "efgh");
   new_node = stack_push(&head, new_string);

   new_string = (char *)malloc(sizeof(char)*(strlen("wxyz")+1));
   strcpy(new_string, "wxyz");
   new_node = stack_push(&head, new_string);

   new_string = (char *)malloc(sizeof(char)*(strlen("aabc")+1));
   strcpy(new_string, "aabc");
   new_node = stack_push(&head, new_string);

   new_string = (char *)malloc(sizeof(char)*(strlen("xxyz")+1));
   strcpy(new_string, "xxyz");
   new_node = stack_push(&head, new_string);

   new_node = head;
   while (new_node != NULL) {
      printf("%s->", (char*)new_node->ptr);
      new_node = new_node->next;
   }
   printf("NULL\n");

   while (head != NULL) {
      lnode *removed_node = stack_pop(&head);
      printf("%s\n", (char*)removed_node->ptr);
      lnode_destroy(removed_node, free); 
   }

   lnode_destroy(head, free);

   return EXIT_SUCCESS;
}
