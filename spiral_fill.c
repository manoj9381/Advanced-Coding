#include <stdlib.h>
#include <stdio.h>
void spiralFill(int m,int n,int arr[m][n]);
int main()
{
int n,m;
printf("\nInput the number of rows : ");
scanf("%d",&m);
printf("\nInput the number of columns : ");
scanf("%d",&n);
int arr[m][n];
spiralFill(m,n,arr);
return 0;
}
void spiralFill(int m,int n,int arr[m][n])
{
	int i,j,sri=0,eri=m-1,sci=0,eci=n-1,num=1;
 	while (sri<=eri && sci<=eci) { 
 		printf("in while %d<=%d=%d && %d<=%d=%d\n",sri,eri,sri<=eri,sci,eci,sci<=eci);
        /* Print the first row  */
        for (j=sci; j<=eci; j++) 
       		arr[sri][j]=num++; 
        for (i = sri+1; i <=eri-1; i++)  
            arr[i][eci]=num++; 
        if (sri < eri)  
            for (j=eci; j >= sci; j--) 
                arr[eri][j]=num++; 
        if (sci < eci)  
            for (i = eri-1; i >= sri+1; i--)  
                arr[i][sci]=num++; 
                     
        sri++;eri--;sci++;eci--;
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
}

