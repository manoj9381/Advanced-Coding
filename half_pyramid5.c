#include <stdio.h>
int main() 
{
   int i, j,k, rows;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   k=1;
   for (i = 1; i <=rows; i++) 
   {
      for (j = 1; j <=i; j++) 
	  {
         printf("%d ",k++);
      }
      printf("\n");
   }
   return 0;
}

