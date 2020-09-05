#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define size 100
#define item char
item s[size];
int top=-1;

void push(char x)
{
	
 if(top==size-1)
 {
 printf("Stack overflow\n");
 exit(1);
}
 else
 {
 top++;
 s[top]=x;
 }
 
}

char pop()
{
 int x;
 if(top==-1)
 {
 printf("Stack Underflow\n");
 exit(1);
}
 else
 {
 	printf("%c",s[top--]);
 }
}


int main()
{
	char str[100];
	int len,i=0;
	printf("Enter string:");
	gets(str);
	len=strlen(str);
	while(str[i]!='\0')
	{
		push(str[i]);
		i++;
	}
	for(i=0;i<len;i++)
	{
		pop();
	}	
}

