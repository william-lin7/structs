#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

void print_list(struct node *n){
  while (n){
    printf("%d ", n->i);
    n = n -> next;
  }
}

struct node * insert_front(struct node *n, int x){
  struct node *n1 = (struct node*)malloc(sizeof(struct node));
  n1->i = x;
  n1->next = n;
  return n1;
}

struct node * free_list(struct node *n){
  struct node *first = n;
  struct node *temp;
  while (n){
    printf("freeing node: %d\n", n->i);
    temp = n->next;
    free(n);
    n = temp;
  }
  free(temp);
  temp = NULL;
  first = NULL;
  return first;
}

struct node * remove_node(struct node *front, int data){
  struct node *first = front;
  struct node *previous = front;
  while (front){
    if (front->i == data){
      if (previous == front){
        free(front);
        front = NULL;
      }
      else{
        previous->next = front->next;
        free(front);
        front = NULL;
      }
      break;
    }
    else{
      previous = front;
      front = front->next;
    }
  }
  return first;
}
