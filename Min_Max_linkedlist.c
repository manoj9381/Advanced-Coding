#include <stdio.h>  
#include<stdlib.h>
struct node{  
    int data;  
    struct node *next;  
};    
struct node *head, *p = NULL;  
void addNode(int data) {  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  
     
    if(head == NULL) {  
        head = newNode;  
        p = newNode;  
    }  
    else {  
        p->next = newNode;  
        p = newNode;  
    }  
}  
   
void minNode() {  
    struct node *current = head;  
    int min;  
     
    if(head == NULL) {  
        printf("List is empty \n");  
    }  
    else {  
        min = head->data;  
        while(current != NULL){  
             if(min > current->data) {  
                 min = current->data;  
             }  
             current= current->next;  
        }          
        printf("Minimum value node in the list: %d\n", min);  
    }  
}  
void maxNode() {  
    struct node *current = head;  
    int max;  
     
    if(head == NULL) {  
        printf("List is empty \n");  
    }  
    else {  
        max = head->data;  
         
        while(current != NULL){  
             if(max < current->data) {  
                 max = current->data;  
             }  
             current = current->next;  
        }              
        printf("Maximum value node in the list: %d\n", max);  
    }  
}  
     
int main()  
{  
    int x;
    printf("Enter elements into linked list ending with 0: ");
    scanf("%d",&x);
    while(x!=0)
    {
    addNode(x);
    scanf("%d",&x);
}
    minNode();  
    maxNode();  
         
    return 0;  
}  

