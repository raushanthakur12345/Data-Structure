//Linear Queue implementation using Array
#include<stdio.h>
#include<stdlib.h>
#define MAX 6

int LQ[MAX];
int front = 0;
int rear = -1;

void enQueue(int x){
	if(rear == MAX-1){
		printf("\n Queue is Full");
		return;
	}
	rear = rear + 1;
	LQ[rear] = x; // LQ[++rear] = x;
}

int deQueue(){
	int x;
	if(front > rear){
		printf("\n Queue is Empty");
		return -1;
	}
	x = LQ[front];
	front = front + 1; // x = LQ[front++]
	return x;
}

void showQueue(){
	if(front > rear){
		printf("\n Queue is empty");
		}
	else {
		printf("\n Current Status of Queue:");
		for(int i=front;i<=rear;i++){
			printf("%d ",LQ[i]);
		}
	}
}
int main(){
	int x,v;
	while(1){
		printf("\n Press 1 to insert an element");
		printf("\n Press 2 to delete an element");
		printf("\n Press 3 to show the Queue");
		printf("\n Press 4 to exit");
		scanf("%d",&x);
		switch(x){
			case 1:
					printf("\n Enter a value to be inserted:");
					scanf("%d",&v);
					enQueue(v);
					break;
			case 2:
					v = deQueue();
					if(v!= -1)
						printf("\n The deleted element is %d",v);
					break;
			case 3:
					showQueue();
					break;
			case 4:
					exit(0);
		}
	}
}