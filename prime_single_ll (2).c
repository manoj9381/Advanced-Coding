#include <stdio.h>  
#include<stdlib.h>
#include<stdbool.h>
struct node
{  
    int data;  
    struct node *next;  
   
};    
struct node *head,*p = NULL;  

struct node* push(struct node* head, int new_data)  
{  
    struct node *temp;
	/* allocate node */
    struct node* new_node =  (struct node*) malloc(sizeof(struct node));  
  
    /* put in the data */
    new_node->data = new_data;  
  	new_node->next = NULL;  
    /* link the old list off the new node */
    if(head==NULL)
    {
    	head=new_node;
    	return head;
	}
    else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_node;
		return head;
	 } 
}  

void deleteNode(struct node* head,  struct node *del)
{
    struct node *temp=head ;
    if (head== NULL || del == NULL)
        return;
 
    if (head == del)
        head = del->next;
   
    while (temp->next != del) {
        temp = temp->next;
    }
    temp->next = del->next;
    free(del);
 
    return;
}

int isPrime(int a);
int primeNode(struct node *head)
{  
    struct node *ptr = head,*next;  
//    int a,t,s;  
    while (ptr != NULL) {
        next = ptr->next;
        // if true, delete node 'ptr'
        if (isPrime(ptr->data))
            deleteNode(head,ptr);
        ptr = next;
    }
}  
int isPrime(int a)
{
int c=1,i;
for(i=1;i<=a/2;i++)
{
if(a%i==0)
{
c++;
}
}
if(c==2)
{
return true;
}
else{
return false;
}
}
 
void printList(struct node *head)  
{  
struct node *temp=head;
    while (temp != NULL)  
    {  
        printf("%d->", temp->data);  
        temp = temp->next;  
    }  
    printf("NULL\n");  
}      
int main()  
{  
    int x;
    printf("Enter elements into double linked list ending with 0: ");
    scanf("%d",&x);
    while(x!=0)
    {
    head=push(head,x);
    scanf("%d",&x);
}
	printList(head);
    primeNode(head);
    printf("list is:");
    printList(head);
     return 0;  
}  
