#include <stdio.h>
int main() {
   int i, space, rows, j;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (i = 1; i <= rows; ++i) {
      for (space = 1; space <= rows - i; ++space) {
         printf("  ");
      }
      for(j=1;j <=i;j++) {
      	if(j==1)
         printf("*");
        else
        printf("   *");
      }
      printf("\n");
   }
   return 0;
}
