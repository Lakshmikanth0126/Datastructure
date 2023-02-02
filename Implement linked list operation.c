#include <stdio.h>
#include <stdlib.h>


struct node {
  int data;
  struct node *next;
};


void push(struct node** head_ref, int new_data) {
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}


void append(struct node** head_ref, int new_data) {
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  struct node *last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  while (last->next != NULL)
    last = last->next;
  last->next = new_node;
  return;
}


void insertAfter(struct node* prev_node, int new_data) {
  if (prev_node == NULL) {
    printf("The given previous node cannot be NULL");
    return;
  }
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}


void deleteNode(struct node** head_ref, int key) {
  struct node* temp = *head_ref, *prev;
  if (temp != NULL && temp->data == key) {
    *head_ref = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) return;
  prev->next = temp->next;
  free(temp);
}

void printList(struct node *node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
}

int main() {
  struct node* head = NULL;
  push(&head, 1);
  append(&head, 2);
  append(&head, 3);
  insertAfter(head->next, 4);
  deleteNode(&head, 2);
  printf("Created Linked List: ");
  printList(head);
  return 0;
}

