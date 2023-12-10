#include<stdio.h>
int main (){
  int number;
  int sum= 0;
  for (int i = 1; i <= 5; ++i) {
      printf("Enter a n%d: ", i);
      scanf("%d", &number);
      if (number < 0) {
          continue;
      }
      sum += number;
  }
  printf("\nSum = %d ", sum );
}








