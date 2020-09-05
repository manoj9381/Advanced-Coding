#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<String.h>
#define SIZE 6
#include<string.h>
char s1[SIZE][SIZE],s2[SIZE][SIZE];
char x[SIZE],z[SIZE];
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
void push_stack1(char x[10])
{
        if( isFull(top1) )
        {
                printf("\nStack Overflow\n");
                return;
        }
        top1++;
        strcpy(s1[top1],x);
}/*End of push()*/
void push_stack2(char x[10])
{
        if( isFull(top2) )
        {
                printf("\nStack Overflow\n");
                return;
        }
         top2++;
        strcpy(s2[top2],x);
}/*End of push()*/
 
const char* pop_stack1()
{
        int item;
        if( isEmpty(top1) )
        {
                printf("\nStack Underflow\n");
                return "error";
        }
        strcpy(x,s1[top1]);
        top1--;
        return x;
}/*End of pop()*/

 const char* pop_stack2()
{
        int item;
        if( isEmpty(top2) )
        {
                printf("\nStack Underflow\n");
                return "error";
        }
        strcpy(z,s2[top2]);
        top2--;
        return z;
}/*End of pop()*/

//Functions to Print Stack 1 and Stack 2
void print_stack1 ()
{
  int i;
  for (i = top1; i >= 0; --i)
  {
   printf("%s \n",s1[i]);
  }
  printf ("\n");
}
void print_stack2 ()
{
  int i;
  for (i = top2; i >=0; --i)
  {
    printf ("%s\n ", s2[i]);
  }
  printf ("\n");
}

int sizeOf(int top)
{
	int i,size=0;
	for(i=0;i<=top;i++)
	{
		size++;
	}
	return size;
}
bool are_equal() {
	int i;
	const char* x1,*x2;
    while ( 1 ) {
//       printf("in are equal while\n");
       bool e1 = isEmpty(top1);
       bool e2 = isEmpty(top2);
//       printf("in are equal e1=%d e2=%d\n",e1,e2);
       printf("top1=%d, top2=%d\n",top1,top2);
       if (e1 && e2) return true;                    // equal
       else if (e1 || e2) return false;                   // not equal
       else if(sizeOf(top1)==sizeOf(top2)){
//       	printf("before for sizeof top1=%d\n",top1);
       	for(i=top1;i>=0;i--)
       	{
//       		printf("sizeof top1=%d\n",top1);
       		printf("pop1=%s pop2=%s\n",x1=pop_stack1(),x2=pop_stack2());
       		if (strcmp(x1,x2)!=0)
			{
//				printf("in if");
				return false;
			}
//			printf("i=%d",i);
		}
       	return true;
        }
	    // not equal
    }
}
int main()
{
int a,b,ch;
const char *y;
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
scanf("%s",x);
push_stack1(x);
break;
case 2:printf("Enter the element\n");
scanf("%s",z);
push_stack2(z);
break;
case 3:y=pop_stack1();
if(y=="error")
printf("stack is empty cannot pop");
else
printf("popped element is %d",y);
break;
case 4:y=pop_stack2();
if(y=="error")
printf("stack is empty cannot pop");
else
printf("popped element is %d",y);
break;
case 5:print_stack1();
break;
case 6:print_stack2();
break;
case 7: eq=are_equal();
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
