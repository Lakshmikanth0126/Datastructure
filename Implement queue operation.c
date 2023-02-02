#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
  int front, rear;
  int a[MAX_SIZE];
};

struct Queue *createQueue() {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->front = q->rear = -1;
  return q;
}


int isEmpty(struct Queue *q) {
  return q->front == -1;
}

int isFull(struct Queue *q) {
  return q->rear == MAX_SIZE - 1;
}

void enqueue(struct Queue *q, int data) {
  if (isFull(q)) {
    printf("Error: Queue is full\n");
    return;
  }
  q->a[++q->rear] = data;
  if (q->front == -1)
    q->front = q->rear;
}

int dequeue(struct Queue *q) {
  if (isEmpty(q)) {
    printf("Error: Queue is empty\n");
    return -1;
  }
  int data = q->a[q->front];
  if (q->front == q->rear)
    q->front = q->rear = -1;
  else
    q->front++;
  return data;
}

void display(struct Queue *q) {
  if (isEmpty(q)) {
    printf("Error: Queue is empty\n");
    return;
  }
  printf("Elements of the queue: ");
  for (int i = q->front; i <= q->rear; i++)
    printf("%d ", q->a[i]);
  printf("\n");
}

int main() {
  struct Queue *q = createQueue();

  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);

  display(q);

  printf("Dequeued element: %d\n", dequeue(q));
  display(q);

  return 0;
}

