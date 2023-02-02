#include <stdio.h>

#define MAX_SIZE 100

int array[MAX_SIZE];
int size = 0;

void insert(int element, int position) {
  int i;
  if (position < 0 || position > size) {
    printf("Invalid position\n");
    return;
  }
  for (i = size - 1; i >= position; i--) {
    array[i + 1] = array[i];
  }
  array[position] = element;
  size++;
}

void delete(int position) {
  int i;
  if (position < 0 || position >= size) {
    printf("Invalid position\n");
    return;
  }
  for (i = position; i < size - 1; i++) {
    array[i] = array[i + 1];
  }
  size--;
}

void display() {
  int i;
  printf("Elements in the array: ");
  for (i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int choice, element, position;
  while (1) {
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the element to be inserted: ");
        scanf("%d", &element);
        printf("Enter the position: ");
        scanf("%d", &position);
        insert(element, position);
        break;
      case 2:
        printf("Enter the position: ");
        scanf("%d", &position);
        delete(position);
        break;
      case 3:
        display();
        break;
      case 4:
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}

