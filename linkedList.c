#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct linked{
  int val;
  struct linked *next;
};
//will be used to prase through the list
struct test_struct *head = NULL;

struct linked* createList(int x){
  struct linked *start = (struct linked*)malloc(sizeof(struct linked));
  start->val = x;
  start->next = NULL;
  head = start;
  return head;
}

struct linked* insert_front(int x){
  if (head==NULL){
    createList(x);
  }
  struct linked *node = (struct linked*)malloc(sizeof(struct linked));
  node -> val = x;
  node -> next = head;
  head = node;
  return node;
}
void print_list(){
  struct linked *start = head;
  while(start != NULL){
    printf("[%d] \n", start->val);
    start = start->next;
  }
  return;
}
void free_list(){
  struct linked *start = head;
  struct linked *next = start->next;
  while(start != NULL){
    free(start);
    start = next;
    next = start->next;
  }
}
int main(){
  int i = 0;
  for(i = 5; i<10; i++){
    insert_front(i);
  }
  print_list(); /*it works!!!
 [9]
 [8]
 [7]
 [6]
 [5]
 [5]
 */
 free_list();
  return 0;
}
