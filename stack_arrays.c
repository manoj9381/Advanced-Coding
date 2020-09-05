#include <stdio.h>
#include <stdlib.h>
struct Stack
{
 int size;
 int top;
 int *S;
};

void Display(struct Stack st)
{
 int i;
 for(i=st.top;i>=0;i--)
 printf("%4d",st.S[i]);
 printf("\n");

}

void push(struct Stack *st,int x)
{
 if(st->top==st->size-1)
 {
 printf("Stack overflow\n");
 exit(1);
}
 else
 {
 st->top++;
 st->S[st->top]=x;
 }
 
}

int pop(struct Stack *st)
{
 int x;
 if(st->top==-1)
 {
 printf("Stack Underflow\n");
 exit(1);
}
 else
 {
 x=st->S[st->top];
 st->top--;
 }
 return x;
 
}

int peek(struct Stack st,int pos)
{
 int x;
 if(st.top-pos+1<0)
 {
 printf("Invalid Index \n");
 exit(1);
}
else
{
 x=st.S[st.top-pos+1];
}
 return x;
}

int isEmpty(struct Stack st)
{
 if(st.top==-1)
 return 1;
 return 0;
}

int isFull(struct Stack st)
{
 return st.top==st.size-1;
}

int stackTop(struct Stack st)
{
 if(!isEmpty(st))
 return st.S[st.top];
 return -1;
}

int main()
{
 struct Stack st;
 int ch,x,d,pos;
 printf("Enter Size\n");
 scanf("%d",&st.size);
 st.top=-1;
 st.S=(int *)malloc(st.size*sizeof(int));

 do
	{
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Stacktop\n6.Exit");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter element to insert:\n");
				scanf("%d",&x);
				push(&st, x);
				break;
				
			case 2:
				d=pop(&st);
				printf("Popped element:%d\n",d);
				break;
				
			case 3:
				printf("Enter position:\n");
				scanf("%d",&pos);
				x=peek(st,pos);
				printf("Element at %d is %d\n",pos,x);
				break;
				
			case 4:
				Display(st);
				break;
				
			case 5:
				x=stackTop(st);
				printf("Stack top is:%d\n",x);
				break;
				
			case 6:
				exit(1);
						
				
		}
		
	}while(ch<=6);
}

