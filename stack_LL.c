#include <stdio.h>
#include <stdlib.h>

struct Node
{
 int data;
 struct Node *next;
}*top=NULL;

void push(int x)
{
 struct Node *t;
 t=(struct Node*)malloc(sizeof(struct Node));
 if(t==NULL)
 printf("stack is full\n");
 else
 {
 t->data=x;
 t->next=top;
 top=t;
 }

}
int pop()
{
 struct Node *t;
 int x=-1;

 if(top==NULL)
 printf("Stack is Empty\n");
 else
 {
 t=top;
 top=top->next;
 x=t->data;
 free(t);
  return x;
 }

}


void display()
{
 struct Node *p;
 p=top;
 while(p!=NULL)
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
 		printf("1.Push\n");
 		printf("2.Pop\n");
 		printf("3.display\n");
 		printf("Enter your choice\n");
 		scanf("%d",&ch);
 		switch(ch)
		 {
 			case 1:
			 	printf("Enter element:\n");
 				scanf("%d",&x);
 				push(x);
 				break;
 			
 			case 2:
 				printf("popped element:\n");
 				x=pop();
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
