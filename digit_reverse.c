#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 100 

int stack[SIZE];
int top=-1;
int main()
{
	int number,a; 
	printf("enter number:");
	scanf("%d",&number);
    a=reverse_number(number);
    
    
	printf("reverse of a number=%d",a); 
      
    return 0; 
}
void push(int item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}
int pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}
int Isempty()
{
	if(top==-1)
	return 1;
	else 
	return 0;
}
int peek(int stack[])
{
if(top == -1)
{
printf("\n STACK IS EMPTY");
return -1;
}
else
return (stack[top]);
}
int reverse_number(int number)
{
	int j;
	push_digits(number);
	int reverse = 0,value; 
    int i = 1; 
    while (!Isempty())  
    { 
     value=peek(stack);
     reverse = reverse + (value * i);
     pop();
     i=i*10;
	}
	return reverse;
}
int push_digits(int number1) 
{ 
    while (number1 != 0)  
    { 
        push(number1 % 10); 
        number1 = number1 / 10; 
    } 
    return;
} 

