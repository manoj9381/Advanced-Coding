#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define maxsize 100
#define item char
item s[maxsize];
int top;
void push(item x);
item pop();
int isoperator(item x);
int isp(item x);
int icp(item x);
item stacktop();
main()
{
char exp[100],ch,pre[1000];
int i=0,j=0,l;
top=-1;
push('#');
printf("enter expression");
gets(exp);
l=strlen(exp);
i=l-1;
while(i>=0)
{
if(isalnum(exp[i]))
{
pre[j++]=exp[i];
}
else if(isoperator(exp[i]))
{
while(isp(stacktop())>icp(exp[i]))
{
	ch=pop();
    pre[j++]=ch;      
}
push(exp[i]);
}
else if(exp[i]==')')
push(')');
else
{
while(stacktop()!=')')
{
ch=pop();
pre[j++]=ch;
}
ch=pop();
}
i--;
}
while(top!=0)
{
ch=pop();
pre[j++]=ch;
}
printf("prefix expression is \n");
puts(strrev(pre));
}
void push(item x)
{
if(top==maxsize-1)
{
printf("stack is full");
exit(1);
}
top++;
s[top]=x;
}
item pop()
{
item x1;
if(top!=0)
{
x1=s[top];
top--;
return x1;
}
}
item stacktop()
{
item x;
if(top!=0)
{
x=s[top];
return x;
}
}
int isoperator(char ch)
{
if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
return 1;
else 
return 0;
}
int isp(char ch)
{
if(ch=='+'||ch=='-')
return 1;
if(ch=='*'||ch=='/')
return 2;
if(ch==')')
return 0;
if(ch=='^')
return 3;
}
int icp(char ch)
{
if(ch=='+'||ch=='-')
return 1;
if(ch=='*'||ch=='/')
return 2;
if(ch==')')
return 5;
if(ch=='^')
return 4;
if(ch=='#')
return -1;
}


