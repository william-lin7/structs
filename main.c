#include <stdio.h>
#include <stdlib.h>

#include "headers.h"


int main(){
  printf("\ntesting print_list\n");
  printf("printing empty list:\n[   ]\n");
  printf("\ndata inserted into linked list: \n[ ");
  struct node *a = (struct node*)malloc(sizeof(struct node));
  a->i = 1;
  struct node *b = (struct node*)malloc(sizeof(struct node));
  b->i = 2;
  a->next = b;
  b->next = NULL;
  print_list(a);
  printf("]");

  printf("\n\ntesting insert_front\n");
  printf("memory of current first in list:   %p\n", a);
  printf("data of current first in list:   %d\n", a->i);
  struct node *p1 = insert_front(a, 3);
  printf("memory of new first in list:   %p\n", p1);
  printf("data of new first in list:   %d", p1->i);
  printf("\nupdated data in linked list: \n[ ");
  print_list(p1);
  printf("]\n");

  printf("\ntesting remove_node\n");
  printf("removing 2:\n[ ");
  print_list(remove_node(p1, 2));
  printf("]\n");

  printf("\ntesting free_list\n");
  struct node *k = free_list(p1);
  printf("printing updated list:\n[ ");
  printf(" ]\n\n");
}
