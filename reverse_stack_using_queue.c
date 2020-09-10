// A C program to demonstrate linked list based implementations of queue and stack 
#include <stdlib.h>  
#include <stdio.h>  
#include <limits.h>  
 
// A linked list (LL) node to store a queue entry  
struct QNode  
{  
	int key;  
	struct QNode *qnext;  
};  
 
// A structure to represent a stack  
struct StackNode  
{  
	int data;  
	struct StackNode* next;  
};  
 
// The queue, front stores the front node of LL and rear stores the last node of LL  
struct Queue  
{  
	struct QNode *front, *rear;  
};  
 
// A utility function to create a new linked list node for the queue.  
struct QNode* newNode(int k)  
{  
	struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));  
	temp->key = k;  
	temp->qnext = NULL;  
	return temp;  
}  
 
// A utility function to create a new linked list node for the stack.  
struct StackNode* newNod(int data)  
{  
	struct StackNode* stackNode =  
			(struct StackNode*) malloc(sizeof(struct StackNode));  
	stackNode->data = data;  
	stackNode->next = NULL;  
	return stackNode;  
}  
 
// Check if the stack is empty 
int isEmpty(struct StackNode *root)  
{  
	return !root;  
}  
 
 
// A utility function to create an empty queue  
struct Queue *createQueue()  
{  
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));  
	q->front = q->rear = NULL;  
	return q;  
}  
 
// The function to add a key k to queue 
void enQueue(struct Queue *q, int k)  
{  
	// Create a new LL node  
	struct QNode *temp = newNode(k);  
 
	// If queue is empty, then new node is front and rear both  
	if (q->rear == NULL)  
	{  
	q->front = q->rear = temp;  
	printf("inserted element into queue is %d value=%d\n",temp,temp->key); 
	return;  
	}  
 
	// Add the new node at the end of queue and change rear 

	q->rear->qnext = temp; 
	printf("in enqueue q->rear->qnextaddr=%d value=%d\n",q->rear->qnext,*(q->rear->qnext)) ; 
	q->rear = temp; 
	printf("inserted element into queue is %d value=%d\n",temp,temp->key); 
}  
 
// Function to push an element on to the stack 
void push(struct StackNode** root, int data)  
{  
	struct StackNode* stackNode = newNod(data);  
	printf("stacknode addr=%d\n",stackNode);
	stackNode->next = *root;  
	*root = stackNode;  
	//printf("in push root=%d\n",root);
	printf("%d pushed to stack\n", data);  
}  
 
// Function to remove a key from given queue q  
struct QNode *deQueue(struct Queue *q)  
{  
	// If queue is empty, return NULL.  
	if (q->front == NULL)  
	return NULL;  
 
	// Store previous front and move front one node ahead  
	struct QNode *temp = q->front;  
	printf("in dequeue q->front=%d q->front->qnext=%d\n", q->front,q->front->qnext);
	q->front = q->front->qnext;  
 
	// If front becomes NULL, then change rear also as NULL  
	if (q->front == NULL)  
	q->rear = NULL;  
	return temp;  
}  
 
// Function to pop an element from the stack 
int pop(struct StackNode** root)  
{  
	if (isEmpty(*root))  
		return INT_MIN;  
	struct StackNode* temp = *root;  
	*root = (*root)->next;  
	int popped = temp->data;  
	printf("popped ele from stack is %d\n",temp->data);
	free(temp);  
 
	return popped;  
}  
 
// Function to get the data at the top of the stack without popping it 
int peek(struct StackNode* root)  
{  
	if (isEmpty(root))  
		return INT_MIN;  
	return root->data;  
}  
 
// Driver to test functions  
int main()  
{  
	struct Queue *q = createQueue();  
	struct StackNode* root = NULL;  
	printf("root=%d\n",&root); 
	push(&root, 10); 
	push(&root, 20);  
	push(&root, 30); 
	// At this point the stack has the elements 10,20,30 with 10 at the bottom and 30 at the top 
	 
	int element = pop(&root); //take out 30 from the stack top 
	enQueue(q, element); //insert it into the first position of the queue 
	 
	element = pop(&root); //now take out 20 from the stack top 
	enQueue(q, element); //insert it into the second position of the queue 
	 
	element = pop(&root); //now take out 10 from the stack top 
	enQueue(q, element); //insert it into the third position of the queue 
	 
	// At this point the stack is empty and the queue has the elements 30,20,10 in sequence 
	 
	struct QNode *qElement = deQueue(q); // take out 30 from the front 
	if(qElement != NULL) 
	{ 
		push(&root, qElement->key); // push it to stack 
	} 
	 
	 
	qElement = deQueue(q); // take out 20 from the front 
	if(qElement != NULL) 
	{ 
		push(&root, qElement->key); // push it to stack 
	} 
	 
	qElement = deQueue(q); // take out 10 from the front 
	if(qElement != NULL) 
	{ 
		push(&root, qElement->key); // push it to stack 
	} 
	 
	// At this point the queue is empty and 
	// the stack has the elements 30,20,10 with 30 at the bottom and 10 at the top 
	 
	return 0;  
}  
