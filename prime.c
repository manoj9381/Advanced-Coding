#include <stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node * addnode(int data){
    struct node *ptr;
    struct node*temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    if(head==NULL){
        ptr->next=NULL;
        head=ptr;
         }
    else{
        temp=head;
        while(temp->next!=NULL){
          temp=temp->next;  
        }
        temp->next=ptr;
        ptr->next=NULL;
        
    }
    return head;
}

int prime(int a){
	
int c=0,i;
for(i=1;i<=a;i++)
{
if(a%i==0)
{
c++;
}
}
return c;
}
void removeprimenodes(){
    struct node *temp;
    struct node *temp1;
    temp=head;
    int p;
    while(temp!=NULL){
        p=prime(temp->data);
        if(p==2){
           if(temp==head){
               head=temp->next;
               free(temp);
               temp=head;
               temp1=NULL;
           }
          else{
              temp1->next=temp->next;
              free(temp);
          temp=temp1->next;
          }
        }
        else{
            temp1=temp;
            temp=temp->next;
        }
    }
}
void display(){
    struct node *temp2;
    temp2=head;
    while(temp2!=NULL){
        printf("%d->",temp2->data);
        temp2=temp2->next;
    }
    printf("NULL");
}
int main(){
    int i,n,data;
    printf("enter number of elements in the linkedlist: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	printf("Enter element : ");
        scanf("%d",&data);
        head=addnode(data);
    }
    printf("After removing primenodes\n");
    removeprimenodes();
    display();
    
    
}

