#include<stdio.h> 
#include<stdlib.h>  
/* A linked list node */
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
// Utility function to create a new Node 
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
  
/* Function to remove duplicates from a 
   unsorted linked list */
void removeDuplicates(struct Node *start) 
{ 
    struct Node *ptr1, *ptr2, *dup; 
    ptr1 = start; 
  
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) 
    { 
        ptr2 = ptr1; 
  
        /* Compare the picked element with rest 
           of the elements */
        while (ptr2->next != NULL) 
        { 
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data) 
            { 
                /* sequence of steps is important here */
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                free(dup); 
            } 
            else /* This is tricky */
                ptr2 = ptr2->next; 
        } 
        ptr1 = ptr1->next; 
    } 
} 
  
/* Function to print nodes in a given linked list */
void printList(struct Node *head)  
{  
struct Node *temp;
temp=head;
    while (temp != NULL)  
    {  
        printf("%4d", temp->data);  
        temp = temp->next;  
    }  
    
}  
  
/* Druver program to test above function */
int main() 
{ 
    /* The constructed linked list is: 
     10->12->11->11->12->11->10*/
    struct Node* head = NULL;  
    int i,ch;  
  	while(1)
  	{
  		printf(" 1.push\n 2.display\n 3.removeduplicates\n 4.exit\n");
  		printf("Enter ur choice");
  		scanf("%d",&ch);
  		switch(ch)
  		{
  			case 1: printf("enter the element to be inserted");
			  		scanf("%d",&i);
					head=push(head, i);
					break;
			case 2: printList(head);
					break;
			case 3:removeDuplicates(head);
					break;
			case 4: exit(0);  	
		}
	  }
  
    return 0; 
}
