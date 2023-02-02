#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
  int top;
  int a[MAX_SIZE];
};

int isEmpty(struct Stack *s) {
  return s->top == -1;
}
int isFull(struct Stack *s) {
  return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, int data) {
  if (isFull(s)) {
    printf("Error: Stack is full\n");
    return;
  }
  s->a[++s->top] = data;
}
int pop(struct Stack *s) {
  if (isEmpty(s)) {
    printf("Error: Stack is empty\n");
    return -1;
  }
  return s->a[s->top--];
}

int peek(struct Stack *s) {
  if (isEmpty(s)) {
    printf("Error: Stack is empty\n");
    return -1;
  }
  return s->a[s->top];
}

int main() {
  struct Stack s;
  s.top = -1;

  push(&s, 1);
  push(&s, 2);
  push(&s, 3);
  printf("Top element is %d\n", peek(&s));
  pop(&s);
  printf("Top element is %d\n", peek(&s));
  return 0;
}

