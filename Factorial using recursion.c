#include <
stdio.h>

int factorial(int n) {
  if (n == 0)
    return 1;
  else
    return n * factorial(n-1);
}

int main() {
  int n, result;
  
  printf("Enter a positive integer: ");	
  scanf("%d", &n);
  
  result = factorial(n);
  printf("Factorial of %d = %d\n", n, result);
  
  return 0;
}

