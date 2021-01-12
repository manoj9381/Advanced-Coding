#include <stdio.h>
int main() {
   int i, space, rows, j,k=0;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (i = 1; i <= rows; ++i, j = 0) {
      for (space = 1; space <= rows - i; ++space) {
         printf(" ");
      }
      for(j=0;j != 2 * i - 1;j++) {
         printf("%d ",++k);
    	}
      printf("\n");
   }
   return 0;
}
