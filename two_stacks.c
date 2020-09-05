#include<stdio.h>
#include<stdlib.h>
#define SIZE 6
int s[SIZE];
int top1 = -1;
int top2 = SIZE;
void push_stack1 (int data)
{
  if (top1 < top2 - 1)
  {
    s[++top1] = data;
  }
  else
  {
    printf ("Stack Full! Cannot Push\n");
  }
}
void push_stack2 (int data)
{
  if (top1 < top2 - 1)
  {
    s[--top2] = data; 
  }
  else
  {
    printf ("Stack Full! Cannot Push\n");
  }
}

//Functions to pop data
void pop_stack1 ()
{
  if (top1 >= 0)
  {
    int popped_value = s[top1--];
    printf ("%d is being popped from Stack 1\n", popped_value);
  }
  else
  {
    printf ("Stack Empty! Cannot Pop\n");
  }
}
void pop_stack2 ()
{
  if (top2 < SIZE)
  {
    int popped_value = s[top2++];
    printf ("%d is being popped from Stack 2\n", popped_value);
  }
  else
  {
    printf ("Stack Empty! Cannot Pop\n");
  }
}

//Functions to Print Stack 1 and Stack 2
void print_stack1 ()
{
  int i;
  for (i = top1; i >= 0; --i)
  {
    printf ("%d ", s[i]);
  }
  printf ("\n");
}
void print_stack2 ()
{
  int i;
  for (i = top2; i < SIZE; ++i)
  {
    printf ("%d ", s[i]);
  }
  printf ("\n");
}

int main()
{
int a,ch;

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
printf("0.EXIT\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter the element\n");
scanf("%d",&a);
push_stack1(a);
break;
case 2:printf("Enter the element\n");
scanf("%d",&a);
push_stack2(a);
break;
case 3:pop_stack1();
break;
case 4:pop_stack2();
break;
case 5:print_stack1();
break;
case 6:print_stack2();
break;
case 0: exit(0);
break;
}
}

}
