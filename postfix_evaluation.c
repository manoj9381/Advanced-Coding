#include<stdio.h>
#include<math.h>
#include<stdlib.h>
# define item int
# define max 100
item s[max];
int top;
void push(item x);
item pop();
int main()
{
	char exp[100];
	int i,op1,op2,r;
	i=0;
	top=-1;
	printf("enter expression");
	gets(exp);
	while(exp[i]!='\0')
	{
		if(isalnum(exp[i]))
		push(exp[i]-'0');
		else
		{
			switch(exp[i])
			{
				case '+':
					op2=pop();
					op1=pop();
					r=op1+op2;
					break;
				case '-':
					op2=pop();
					op1=pop();
					r=op1-op2;
					break;
				case '*':
					op2=pop();
					op1=pop();
					r=op1*op2;
					break;
				case '/':
					op2=pop();
					op1=pop();
					r=op1/op2;
					break;
				case '^':
					op2=pop();
					op1=pop();
					r=pow(op1,op2);
					break;
					
			
				
			}
			push(r);
			
		}
		i++;
	}
	if(top>0)
	printf("error");
	else
	printf("result=%d",pop());
	
}
void push(item x)
{
	if(top==max-1)
	{
	
	printf("overflow");
	exit(1);
}
top++;
s[top]=x;
}
item pop()
{
	item x1;
	if(top==-1)
	{
		printf("under flow");
		exit(1);
	}
	x1=s[top];
	top--;
	return x1;
}
