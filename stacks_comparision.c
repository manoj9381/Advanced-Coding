#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 4
int s1[SIZE],s2[SIZE];
int top1=-1,top2 = -1;

int isEmpty(int top)
{
        if( top == -1 )
                return 1;
        else
                return 0;
}/*End of isEmpty*/
 
int isFull(int top)
{
        if( top == SIZE-1 )
                return 1;
        else
                return 0;
}/*End of isFull*/
void push_stack1(int data)
{
        if( isFull(top1) )
        {
                printf("\nStack Overflow\n");
                return;
        }
        s1[++top1] = data;
}/*End of push()*/
void push_stack2(int data)
{
        if( isFull(top2) )
        {
                printf("\nStack Overflow\n");
                return;
        }
        s2[++top2] = data;
}/*End of push()*/

 
int pop_stack1()
{
        int item;
        if( isEmpty(top1) )
        {
                printf("\nStack Underflow\n");
                exit(1);
        }
        item = s1[top1];
        top1--;
        return item;
}/*End of pop()*/
int pop_stack2()
{
        int item;
        if( isEmpty(top2) )
        {
                printf("\nStack Underflow\n");
                exit(1);
        }
        item = s2[top2];
        top2--;
        return item;
}/*End of pop()*/
 

//Functions to Print Stack 1 and Stack 2
void print_stack1 ()
{
  int i;
  for (i = top1; i >= 0; --i)
  {
    printf ("%d ", s1[i]);
  }
  printf ("\n");
}
void print_stack2 ()
{
  int i;
  for (i = top2; i >=0; --i)
  {
    printf ("%d ", s2[i]);
  }
  printf ("\n");
}

int sizeOf(int s[],int top)
{
	int i,size=0;
	for(i=top;i>=0;i--)
	{
		size++;
	}
	return size;
}
bool are_equal(int s1[], int s2[]) {
	int i,x1,x2;
    while ( 1 ) {
//    	printf("in are equal while\n");
       bool e1 = isEmpty(top1);
       bool e2 = isEmpty(top2);
//       printf("in are equal e1=%d e2=%d\n",e1,e2);
       if (e1 && e2) return true;                    // equal
       else if (e1 || e2) return false;                   // not equal
       else if(sizeOf(s1,top1)==sizeOf(s2,top2)){
       	for(i=top1;i>=0;i--)
       	{
//       		printf("sizeof\n");
       		printf("pop1=%d pop2=%d\n",x1=s1[i],x2=s2[i]);
       		if (x1 != x2)
			{
//				printf("in if");
				return false;
			}
		   }
       	return true;
        }
	    // not equal
    }
}
int main()
{
int a,b,ch,x;
bool eq;
while(1)
{
printf("Enter your choice");
printf("What do u want to do?\n");
printf("1.Push element in stack 1\n");
printf("2.Push element in stack 2\n");
printf("3.Pop element from stack 1\n");
printf("4.Pop element from stack 2\n");
printf("5.Display stack 1\n");
printf("6.Display stack 2\n");
printf("7.are equal\n");
printf("0.EXIT\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter the element\n");
scanf("%d",&a);
push_stack1(a);
break;
case 2:printf("Enter the element\n");
scanf("%d",&b);
push_stack2(b);
break;
case 3:x=pop_stack1();
if(x==0)
printf("stack is empty cannot pop");
else
printf("popped element is %d",x);
break;
case 4:x=pop_stack2();
if(x==0)
printf("stack is empty cannot pop");
else
printf("popped element is %d",x);
break;
case 5:print_stack1();
break;
case 6:print_stack2();
break;
case 7: eq=are_equal(s1,s2);
if(eq==1)
printf("two stacks are equal");
else
printf("two stacks are not equal");
break;
case 0: exit(0);
break;
}
}

}
