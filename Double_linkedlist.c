#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
};
typedef struct Node* npt;
npt root=NULL;

npt insert_beg(npt root,int x)
{
	npt temp;
	temp=(npt)malloc(sizeof(struct Node));
	temp->data=x;
	if(root==NULL)
	{
		temp->next=NULL;
		temp->prev=NULL;
		root=temp;
	}
	else

	{
		temp->prev=NULL;
		temp->next=root;
		root->prev=temp;
		root=temp;
	}
	return root;
}

npt insert_end(npt root,int x)
{

	npt temp,p;
	temp=(npt)malloc(sizeof(struct Node));
	temp->data=x;

	if(root==NULL)
	{

		temp->next=NULL;
		temp->prev=NULL;
		root=temp;
	}
	else
	{
		p=root;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
		temp->prev=p;
		temp->next=NULL;
	}
	return root;
}

npt insert_mid(npt root,int x,int pos)
{
	int c=1;
	npt temp,p;
	if(pos>count(root))
	{
		printf("Insertion not possible\n");
		return root;
	}
	else if(pos==1)
	{
	
		insert_beg(root,x);
		return ;
	}
	temp=(npt)malloc(sizeof(struct Node));
	temp->data=x;
	p=root;
	while(p->next!=NULL && c<pos-1)
	{
		c++;
		p=p->next;
	}
	temp->next=p->next;
	p->next->prev=temp;
	temp->prev=p;
	p->next=temp;
	return root;
}

void display(npt root)
{ 
	
	npt temp;
	temp=root;
	if(temp==NULL)
	{
		printf("empty");
		return;
	}
	else{
	while(temp!=NULL)
	{
		printf("%4d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
	
}

int count(npt root)
{
	npt temp=root;
	int c=0;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	return c;
}

npt delete_beg(npt root)
{
	npt temp;
	temp=root;
	root=root->next;
	root->prev=NULL;
	printf("Deleted element:%d\n",temp->data);
	free(temp);
	return root;
}

npt delete_end(npt root)
{
	npt temp,p;
	temp=root;
	while(temp->next!=NULL)
	{
		
		p=temp;
		temp=temp->next;
		
	}
	p->next=NULL;
	printf("Deleted element:%d\n",temp->data);
	free(temp);
	return root;
}

npt delete_mid(npt root, int pos)
{
	int i;
	npt temp=root;
	if(pos>count(root))
	{
		printf("Deletion not possible\n");
		return root;
	}
	else if(pos==1)
	{
		delete_beg(root);
		return;
	}
	else if(pos==count(root))
	{
		delete_end(root);
		return;
	}
	else
	{
	for(i=1;i<pos;i++)
	{
		temp=temp->next;
	}
	if(temp!=NULL)
	{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		printf("Deleted element:%d\n",temp->data);
		free(temp);
	}
}
	return root;
}
	
	
int main()
{
	npt root=NULL;
	int x,ch,pos,c;
	printf("Select your choice:\n");
	printf("1.Insertion at begin\n");
	printf("2.Insertion at end\n");
	printf("3.Insertion at middle\n");
	printf("4.Deletion at begin\n");
	printf("5.Deletion at end\n");
	printf("6.Deletion at middle\n");
	printf("7.Display\n");
	printf("8.Count\n");
	printf("9.Exit\n");
	do
	{
		printf(" enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf(" enter element:\n");
				scanf("%d",&x);
				root=insert_beg(root,x);
				break;
			case 2:
				printf("enter element:\n");
				scanf("%d",&x);
				root=insert_end(root,x);
				break;
			case 3:
				printf("enter element:\n");
				scanf("%d",&x);
				printf("enter position:\n");
				scanf("%d",&pos);
				root=insert_mid(root,x,pos);
				break;
			case 4:
				root=delete_beg(root);
				break;
				
			case 5:
				root=delete_end(root);
				break;
				
			case 6:
				printf("Enter position to delete:\n");
				scanf("%d",&pos);
				root=delete_mid(root,pos);
				break;
				
			case 7:
				display(root);
				break;
	
			case 8:
				c=count(root);
				printf("Count=%d\n",c);
				break;
			case 9:
				exit(1);

		}
	}while(ch<=9);
}


