#include <stdio.h>

int main() {
  int i, x[6], sum = 0;
  
  printf("Enter 6 numbers: ");

  for(i = 0; i < 6; ++i) {
    // Equivalent to scanf("%d", &x[i]);
      scanf("%d", x+i);

  // Equivalent to sum += x[i]
      sum += *(x+i);
  }

  printf("Sum = %d", sum);
  
}