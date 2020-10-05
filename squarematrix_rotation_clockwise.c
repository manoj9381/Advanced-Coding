#include<stdlib.h>
#include<stdio.h>
void transpose(int N,int a[N][N])
{
	int i,j,t;
	for(i=0;i<N-1;i++)
		for(j=i+1;j<=N-1;j++)
		{
			t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}
}
void swapcolumns(int N,int a[N][N])
{
	int i,j1,j2,k,t;
	j1=0;
	j2=N-1;
	while(j1<j2)
	{
		for(i=0;i<=N-1;i++)
		{
			t=a[i][j1];
			a[i][j1]=a[i][j2];
			a[i][j2]=t;
		}
		j1++;j2--;
	}
}
void display(int N,int a[N][N])
{
	int i,j;
	for(i = 0; i < N; i++)
	{
	for(j = 0; j < N; j++)
	{
	printf("%d\t",a[i][j]);
	}
	printf("\n");
	}	
}
int main()
{
int N;
printf("\nInput the N value for square matrix : ");
scanf("%d",&N);
int a[N][N];
int i,j;
printf("\nInput the matrix \n");
	for(i = 0; i < N; i++)
	{
	for(j = 0; j < N; j++)
	{
	scanf("%d",&a[i][j]);
	}
	}
printf("\nThe Matrix before rotation\n");
display(N,a);

transpose(N,a);
printf("\nThe Matrix transpose is\n");
display(N,a);
swapcolumns(N,a);
printf("\nThe Matrix after rotation\n");
display(N,a);

return 0;
}
