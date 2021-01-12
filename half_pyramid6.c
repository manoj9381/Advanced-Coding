#include <stdio.h>
int main() {
   int i, j;
   char input,alphabet;
   printf("Enter an uppercase character you want to print in the last row: ");
   scanf("%c", &input);
   for (i = 1; i <= (input - 'A' + 1); ++i) {
   		alphabet = 'A';
      	for (j = 1; j <= i; ++j) {
         	printf("%c ", alphabet++);
      	}
      printf("\n");
   }
   return 0;
}
