#include<stdio.h> 
#include<stdlib.h> 

struct node 
{
int data;
struct node *link; 
}; 

typedef struct node *npt;
npt insert_end(npt root,int x);
void display(npt root);
void sort(npt root);

int main()
{
	 npt root=NULL; int x,ch,pos;
do	
{
printf("\n select your choice");
printf("\n 1.insert at end \n 2.display \n 3.sort\n 3.exit");
printf("\n enter your choice"); scanf("%d",&ch);
switch(ch){
case 1: printf("\n enter element"); scanf("%d",&x); root=insert_end(root,x);
break;
case 2: display(root); 
break;
case 3: sort(root);
break;
case 4: exit(1);
}
}while(ch<=4);
}

npt insert_end(npt root,int x)	{ npt p,t;
p=(npt)malloc(sizeof(struct node)); p->data=x;
if(root==NULL) { p->link=NULL; root=p;
return p;	} t=root;
while(t->link!=NULL)	
{ t=t->link;	}
t->link=p;
p->link=NULL; return root;	
}

void display(npt root)
{
   npt temp = root;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}
void sort(npt root)
{
    int i,j,a;

    npt temp1,temp2;

    for(temp1=root;temp1!=NULL;temp1=temp1->link)
    {
        for(temp2=temp1->link;temp2!=NULL;temp2=temp2->link)
        {
            if(temp1->data>temp2->data)
            {
			a = temp1->data;
            temp1->data = temp2->data;
            temp2->data = a;
        	}
        }
    }
}
