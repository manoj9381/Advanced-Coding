#include <stdio.h>
int main() {
   int i, j;
   char input, alphabet = 'A';
   printf("Enter an uppercase character you want to print in the last column: ");
   scanf("%c", &input);
   for (i= (input - 'A' + 1);i>=1; --i) {
      for (j = 1; j <= i; ++j) {
         printf("%c ", alphabet++);
      }
      printf("\n");
   }
   return 0;
}
