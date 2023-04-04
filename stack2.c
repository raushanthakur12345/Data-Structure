//Stack implementation using Array
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int stack[SIZE];
int top = -1;

int isFull(){
	if(top == SIZE-1)
		return 1;
	else
		return 0;
	// return top == SIZE-1
}

int isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
}

void push(int x){
	if(isFull()){
		printf("\n Stack is Full");
		return;
	}
	top = top + 1;
	stack[top] = x;
}

int pop(){
	int x;
	if(isEmpty()){
		printf("\n Stack is Empty");
		return -1;
	}
	x = stack[top];
	top = top -1;
	return x;
}

int peek(){
	int x;
	if(isEmpty()){
		printf("\n Stack is Empty");
		return -1;
	}
	x = stack[top];
	return x;
}

void showStack(){
	if(top == -1)
		printf("\n Stack is empty");
	else {
		printf("\n Current Status of Stack:");
		for(int i=top;i>=0;i--){
			printf("\n %d",stack[i]);
		}
	}
}
int main(){
	int x,v;
	while(1){
		printf("\n Press 1 to push an element");
		printf("\n Press 2 to pop an element");
		printf("\n Press 3 to peek an element");
		printf("\n Press 4 to show the stack");
		printf("\n Press 5 to exit");
		scanf("%d",&x);
		switch(x){
			case 1:
					printf("\n Enter a value to be pushed:");
					scanf("%d",&v);
					push(v);
					break;
			case 2:
					v = pop();
					if(v != -1)
						printf("\n The popped element is %d",v);
					break;
			case 3:
					v = peek();
					if(v != -1)
						printf("\n The top element is %d",v);
					break;
			case 4:
					showStack();
					break;
		
			case 5:
					exit(0);
		}
	}
}