#include <stdlib.h>
#include <stdio.h>
void printSpiral(int m,int n,int arr[m][n]);
int main()
{
int n,m;
printf("\nInput the number of rows : ");
scanf("%d",&m);
printf("\nInput the number of columns : ");
scanf("%d",&n);
int arr[m][n];
int i,j;
printf("\nInput the matrix \n");
	for(i = 0; i < m; i++)
	{
	for(j = 0; j < n; j++)
	{
	scanf("%d",&arr[i][j]);
	}
	}
printf("\nThe Matrix is \n");
for(i = 0; i < m; i++)
	{
	for(j = 0; j < n; j++)
	{
	printf("%d\t",arr[i][j]);
	}
	printf("\n");
	}
printSpiral(m,n,arr);
return 0;
}
void printSpiral(int m,int n,int arr[m][n])
{
	int i,j,sri=0,eri=m-1,sci=0,eci=n-1;
 	while (sri<=eri && sci<=eci) { 
 		printf("in while %d<=%d=%d && %d<=%d=%d\n",sri,eri,sri<=eri,sci,eci,sci<=eci);
        /* Print the first row  */
        for (j=sci; j<=eci; j++) { 
            printf("1-arr[%d][%d]=%d\t",sri,j,arr[sri][j]); 
        } 
        printf("\n"); 
        for (i = sri+1; i <=eri-1; i++) { 
            printf("2-arr[%d][%d]=%d \t", i,eci,arr[i][eci]); 
        } 
         printf("\n");  
        if (sri < eri) { 
            for (j=eci; j >= sci; j--) { 
                printf("3-arr[%d][%d]=%d \t",eri,j, arr[eri][j]); 
            } 
        } 
  	 	printf("\n");
        /* Print the first column from the remaining columns */
        if (sci < eci) { 
            for (i = eri-1; i >= sri+1; i--) { 
                printf("4-arr[%d][%d]=%d \t",i,sci, arr[i][sci]); 
            } 
        } 
        printf("\n");
        sri++;eri--;sci++;eci--;
    } 

}

