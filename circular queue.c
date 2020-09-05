#include<stdio.h>
#include<stdlib.h>
# define maxsize 6
# define item int
item cq[maxsize];
int front,rear;
void insert(item x);
void display();
item delete();
int cqfull();
int cqempty();
int main()
{
	int ch,x;
	front=rear=0;
	do
	{
		printf("\nselect your choice");
		printf("\n1.insertion\n2.deletion\n3.display\n4.exit");
		printf("\nenter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(!cqfull())
			{
				printf("\nenter element");
				scanf("%d",&x);
				insert(x);
				
			}
			break;
			case 2:if(!cqempty())
			{
				x=delete();
				printf("\n%d",x);
			}
			else
			{
				printf("\ncq is empty");
			}
			break;
			case 3:if(!cqempty())
			display();
			else
				{
					printf("\ncq is empty");
					
				}
				break;
			case 4:exit(0);
			default:
			printf("enter choice between 1 and 4");			
		}
	}while(ch<=4);
}
int cqfull()
{
	rear=(rear+1)%maxsize;
	if(front==rear)
	{
		if(front==0)
		{
			rear=maxsize-1;
		}
		else
		{
			rear=rear-1;
		}
		return 1;
	}
	else
	{
			return 0;
		}
	}
void insert(item x)
{
	cq[rear]=x;
	
}
int cqempty()
{
	if(front==rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
item delete()
{
	int x1;
	front=(front+1)%maxsize;
	x1=cq[front];
	return x1;
}
void display()
{
	
	int i;
	if(front<rear)
	{
		for(i=front+1;i<=rear;i++)
		{
			printf("%4d",cq[i]);
		}
	}
	else
	{
		for(i=front+1;i<=maxsize-1;i++)
		{
			printf("%4d",cq[i]);
			
		}
		for(i=0;i<=rear;i++)
		{
			printf("%4d",cq[i]);
		}
	}
}

