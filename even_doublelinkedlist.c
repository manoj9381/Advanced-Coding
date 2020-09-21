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

void evenNode()
 {  
    struct node *current = head;  
    int s;  
    if(head == NULL) {  
        printf("List is empty \n");  
    }  
    else
	 {  
        
        while(current != NULL)
        {
        s = current->data;  
		
             if(s%2==0)
			  {  
               
                printf("%d\n",s);
             }  
             current = current->next;  
             
        } 
	            
    }
	
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
printf("Even nodes in the given linked list are: ");
    evenNode();  
    return 0;  
}  

