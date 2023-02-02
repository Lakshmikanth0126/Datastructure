#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
  int top;
  char a[MAX_SIZE];
};

int isEmpty(struct Stack *s) {
  return s->top == -1;
}


int isFull(struct Stack *s) {
  return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, char data) {
  if (isFull(s)) {
    printf("Error: Stack is full\n");
    return;
  }
  s->a[++s->top] = data;
}

char pop(struct Stack *s) {
  if (isEmpty(s)) {
    printf("Error: Stack is empty\n");
    return '\0';
  }
  return s->a[s->top--];
}

char peek(struct Stack *s) {
  if (isEmpty(s)) {
    printf("Error: Stack is empty\n");
    return '\0';
  }
  return s->a[s->top];
}

int priority(char op) {
  if (op == '(')
    return 0;
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  return 3;
}

void infixToPostfix(char *infix, char *postfix) {
  struct Stack s;
  s.top = -1;

  int i = 0, j = 0;
  while (infix[i] != '\0') {
    if (isalnum(infix[i]))
      postfix[j++] = infix[i];
    else {
      while (!isEmpty(&s) && priority(peek(&s)) >= priority(infix[i]))
        postfix[j++] = pop(&s);
      push(&s, infix[i]);
    }
    i++;
  }
  while (!isEmpty(&s))
    postfix[j++] = pop(&s);
  postfix[j] = '\0';
}

int main() {
  char infix[] = "a+b*c";
  char postfix[MAX_SIZE];

  infixToPostfix(infix, postfix);
  printf("Postfix expression: %s\n", postfix);

  return 0;
}

