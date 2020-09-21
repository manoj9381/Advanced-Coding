#include <stdio.h>  
#include<stdlib.h>
struct node
{  
    int data;  
    struct node *next;  
    struct node *prev;
};    
struct node *head, *p = NULL;  

struct node* addNode(struct node* head,int x)
{

	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;

	if(head==NULL)
	{

		temp->next=NULL;
		temp->prev=NULL;
		head=temp;
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
		temp->prev=p;
		temp->next=NULL;
	}
	return head;
}

int prime(int a);
void primeNode() 
{  
    struct node *current = head;  
    int a,t;  
     
    if(head == NULL)
	 {  
        printf("List is empty \n");  
    }  
    else
	 {  
       
        while(current != NULL)
		{  
		 a = current->data;  
        t=prime(a);
             if(t==2)
			  {  
               
                printf("%d\n",a);
             }  
             current = current->next;  
            
        }              
    }  
}  
int prime(int a)
{
int c=1,i;
for(i=1;i<=a/2;i++)
{
if(a%i==0)
{
c++;
}
}
return c;
}
     
int main()  
{  
    int x;
    printf("Enter elements into double linked list ending with 0: ");
    scanf("%d",&x);
    while(x!=0)
    {
    head=addNode(head,x);
    scanf("%d",&x);
}
printf("Prime nodes in the given list are: ");
    primeNode();  
    return 0;  
}  

