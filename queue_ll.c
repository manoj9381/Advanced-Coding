#include <stdio.h>
#include <stdlib.h>

struct Node
{
 int data;
 struct Node *next;

}*front=NULL,*rear=NULL;

void enqueue(int x)
{
 struct Node *t;
 t=(struct Node*)malloc(sizeof(struct Node));
 if(t==NULL)
 printf("Queue is FUll\n");
 else
 {
 t->data=x;
 t->next=NULL;
 if(front==NULL)
 front=rear=t;
 else
 {
 rear->next=t;
 rear=t;
 }
 }

}
int dequeue()
{
 int x=-1;
 struct Node* t;

 if(front==NULL)
 printf("Queue is Empty\n");
 else
 {
 x=front->data;
 t=front;
 front=front->next;
 free(t);
 }
 return x;
}
void display()
{
 struct Node *p=front;
 while(p)
 {
 printf("%d ",p->data);
 p=p->next;
 }
 printf("\n");
}

int main()
 {
 	int ch,x;
 	while(1)
 	{
 		printf("1.Enqueue\n");
 		printf("2.Dequeue\n");
 		printf("3.display\n");
 		printf("4.exit\n");
 		printf("Enter your choice\n");
 		scanf("%d",&ch);
 		switch(ch)
		 {
 			case 1:
			 	printf("Enter element:\n");
 				scanf("%d",&x);
 				enqueue(x);
 				break;
 			
 			case 2:
 				printf("Removed element:\n");
 				x=dequeue();
 				printf("%d\n",x);
 				break;
 				
 			case 3:
 				display();
 				break;
 				
 			case 4:
 				exit(1);
		 }
	 }
 	
 }
