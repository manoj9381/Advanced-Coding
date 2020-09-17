#include<stdio.h>  
#include<stdlib.h>  
  
/* Link list node */
struct Node  
{  
    int data;  
    struct Node* next;  
};  
  
/* Function to get the middle of the linked list*/
void printMiddle(struct Node *head)  
{  
    struct Node *slow_ptr = head;  
    struct Node *fast_ptr = head;  
  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
        printf("The middle element is [%d]\n\n", slow_ptr->data);  
    }  
}  
  
struct Node* push(struct Node* head, int new_data)  
{  
    struct Node *temp;
	/* allocate node */
    struct Node* new_node =  (struct Node*) malloc(sizeof(struct Node));  
  
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
// A utility function to print a given linked list  
void printList(struct Node *ptr)  
{  
    while (ptr != NULL)  
    {  
        printf("%4d", ptr->data);  
        ptr = ptr->next;  
    }   
}  
  
/* Driver program to test above function*/
int main()  
{  
    /* Start with the empty list */
    struct Node* head = NULL;  
    int i,ch;  
  	while(1)
  	{
  		printf(" 1.push\n 2.display\n 3.findmiddle\n 4.exit\n");
  		printf("Enter ur choice");
  		scanf("%d",&ch);
  		switch(ch)
  		{
  			case 1: printf("enter the element to be inserted");
			  		scanf("%d",&i);
					head=push(head, i);
					break;
			case 2:  printList(head);
					break;
			case 3: printMiddle(head);
					break;
			case 4: exit(0);  	
		}
	  }
      
    return 0;  
}  
