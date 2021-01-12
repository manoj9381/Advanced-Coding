#include <stdio.h>
int main() {
   int i, space, rows, j,k=1;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (i = 1; i <= rows; ++i) {
      for (space = 1; space <= rows - i; ++space) {
         printf("  ");
      }
      for(j=0;j <i;j++) {
      	if (j==0)
         printf("%d",k++);
         else
         printf("%3d",k++);
      }
      printf("\n");
   }
   return 0;
}
