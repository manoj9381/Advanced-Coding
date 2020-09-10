//Implementing queue using a single stack


#include<stdio.h>
#define SIZE 10
int stack[10];
int top = -1;

int pop() {
	printf("deleted element is %d\n",stack[top]);
    if(top != -1) return stack[top--];
}
void push(int data) {
    if(top < SIZE) 
	stack[++top] = data;
	printf("element inserted in stack is %d at %d\n",data,top);
}
void enqueue(int data) {
    push(data);
//    printf("in enqueue\n");
}
int dequeue() {
    if(top == 0) 
	return pop();
    int data = pop();
    //printf("in dequeue data=%d\n",data);
//    printf("dequeue called\n");
    int value = dequeue();
//    printf("dequeue returned\n");
//    printf("in dequeue value=%d data=%d\n",value,data);
    push(data);
    return value;
}

int main(void) {

    int i;

    //Enqueue
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printf("after enqueue elements in stack are\n");
    for(i=top;i>=0;i--) 
	printf("%d ",stack[i]);
    printf("\n");

    //Dequeue
//    printf("1st dequeue called\n");
    printf("Dequeue --> %d\n",dequeue());
//    printf("1st dequeue returned\n");
//    printf("2nd dequeue called\n");
    printf("Dequeue --> %d\n",dequeue());
//    printf("2nd dequeue returned\n");
    printf("after dequeue elements in stack are");
    for(i=0;i<=top;i++) printf("%d ",stack[i]);
    printf("\n");

    return 0;

}
