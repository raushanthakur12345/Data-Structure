//Stack implementation using Array
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int x){
	if(top == SIZE-1){
		printf("\n Stack is Full");
		return;
	}
	top = top + 1;
	stack[top] = x;
}

int pop(){
	int x;
	if(top == -1){
		printf("\n Stack is Empty");
		return -1;
	}
	x = stack[top];
	top = top -1;
}

int main(){
	int x,v;
	while(1){
		printf("\n Press 1 to push an element");
		printf("\n Press 2 to pop an element");
		printf("\n Press 3 to exit");
		scanf("%d",&x);
		switch(x){
			case 1:
					printf("\n Enter a value to be pushed:");
					scanf("%d",&v);
					push(v);
					break;
			case 2:
					v = pop();
					printf("\n The popped element is %d",v);
					break;
			case 3:
					exit(0);
		}
	}
}