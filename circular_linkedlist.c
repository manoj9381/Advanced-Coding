#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* link;
};

typedef struct Node* npt;

npt insert_beg(npt head,int x)
{
	npt p,t;
	p=(npt)malloc(sizeof(struct Node));
	if(head==NULL)
	{
		p->data=x;
		p->link=p;
	}
	else
	{
	p->data=x;
	p->link=head;
	t=head;
	while(t->link!=head)
	{
		t=t->link;
	}
	t->link=p;
	head=p;
	return head;
}
}

npt insert_end(npt head,int x)
{
	npt p,t;
	p=(npt)malloc(sizeof(struct Node));
	p->data=x;
	if(head==NULL)
	{
		p->link=NULL;
		head=p;
	}
	p->link=head;
	t= head;
	while (t->link!=head)
		t=t->link;
	t->link=p;
	return head;
}

npt insert_mid(npt head,int x,int pos)
{
	npt p,t;
	int c=1;
	p=(npt)malloc(sizeof(struct Node));
	p->data=x;
	if(pos>count(head))
	{
		printf("Enter valid locatiom to insert\n");
		return head;
	}
	else if(pos==1)
	{
	insert_beg(head,x);
	}
	else
	{
	t=head;
	while(t->link!=head && c<pos-1)
	{
		t=t->link;
		c++;
	}
	p->link=t->link;
	t->link=p;
	return head;
}

}

void display(npt head)
{

	npt temp;
	temp=head;	
	while(temp->link!=head)
	{
	printf("%4d",temp->data);
	temp=temp->link;
	}
printf("%4d\n",temp->data);
}

int count(npt head)
{
	npt temp;
	int c=1;
	if(head==NULL)
	{
		printf("Linked list is empty.\n");
		exit(1);
	}
	temp=head;
	while(temp->link!=head)
	{
		temp=temp->link;
		c++;
	}
    return c;
}

npt delete_beg(npt head)
{
	npt p,temp;
	p=temp=head;
	while(temp->link!= head) 
		temp=temp->link;
	if(temp==head) 
	{
		head=NULL;
		return head;
	}
	temp->link=head->link;  
	head=head->link; 
	printf("Deleted element:%d\n",p->data);
	free(p);
	return head;
}

npt delete_end(npt head)
{
	npt t,q;
	t = head;
	if(t->link== head) 
	{
		printf("deleting element at beginning\n");
		delete_beg(head);
		return NULL;
	}
	else
	{
	while(t->link != head) 
	{
		q=t;
		t=t->link;
	}
		q->link = head;
		printf("Deleted element:%d\n",t->data);
		free(t);
		return head;
	}
}

npt delete_mid(npt head,int pos)
{
	npt t, p;
	int c=1;
	if(pos>count(head))
	{
		printf("Deletion not possible\n");
		return head;
	}
	else if(pos==1)
	{
		delete_beg(head);
	}
	else
	{
		t=head;
		while(t->link!=head && c<=pos-1)
		{
			p=t;
			t=t->link;
			c++;
		}
	
		p->link = t->link;
		printf("Deleted element:%d\n",t->data);
		free(t);
		return head;
		
	}
	
}


int main()
{
	int ch,x,pos,c;
	npt head=NULL;
	printf("Select your chioce:\n");
	printf("1.insertion at begin\n");
	printf("2.insertion at end\n");
	printf("3.insertion at given position\n");
	printf("4.display\n");
	printf("5.count\n");
	printf("6.deletion at begin\n");
	printf("7.deletion at end\n");
	printf("8.deletion at given position\n");
	printf("9.Exit\n");
	do
	{
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter element to insert:\n");
				scanf("%d",&x);
				head=insert_beg(head,x);
				break;
				
			case 2:
				printf("Enter elemet to insert:\n");
				scanf("%d",&x);
				head=insert_end(head,x);
				break;
				
			case 3:
				printf("Enter position to insert:\n");
				scanf("%d",&pos);
				printf("Enter element to insert:\n");
				scanf("%d",&x);
				head=insert_mid(head,x,pos);
				break;
				
			case 4:
				display(head);
				break;
			
			case 5:
				c=count(head);
				printf("Count=%d\n",c);
				break;
				
			case 6:
				head=delete_beg(head);
				break;
				
			case 7:
				head=delete_end(head);
				break;
				
			case 8:
				printf("Enter position:\n");
				scanf("%d",&pos);
				head=delete_mid(head,pos);
				break;
				
			case 9:
				exit(1);			
		}
	}while(ch<=9);	
}

