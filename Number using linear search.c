#include <stdio.h>

int search(int array[], int size, int element) {
  int i;
  for (i = 0; i < size; i++) {
    if (array[i] == element) {
      return i;
    }
  }
  return -1;
}

int main() {
  int array[100], size, element, position;
  printf("Enter the number of elements: ");
  scanf("%d", &size);
  printf("Enter %d elements: ", size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
  printf("Enter the element to search: ");
  scanf("%d", &element);
  position = search(array, size, element);
  if (position == -1) {
    printf("Element not found\n");
  } else {
    printf("Element found at index %d\n", position);
  }
  return 0;
}

