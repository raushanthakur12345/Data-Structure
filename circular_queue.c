//Circular Queue implementation using Array
#include<stdio.h>
#include<stdlib.h>
#define MAX 6

int CQ[MAX];
int front = -1;
int rear = -1;

void enQueue(int x){
	if(front == (rear + 1)%MAX){
		printf("\n Queue is Full");
		return;
	}
	if(front == -1)
		front = 0;
	
	rear = (rear + 1) % MAX;
	CQ[rear] = x;
}

int deQueue(){
	int x;
	if(front == -1){
		printf("\n Queue is Empty");
		return -1;
	}
	x = CQ[front];
	if(front == rear){
		front = -1;
		rear = -1;
	}
	else {
		front = (front + 1)%MAX;
	}
	return x;
}

void showQueue(){
	if(front == -1)
		printf("\n Queue is empty");
	else {
		printf("\n Current Status of Queue:");
		for(int i=front; i != rear; i = (i + 1)%MAX){
			printf("%d ",CQ[i]);
		}
		printf("%d ",CQ[rear]);
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
					if(v != -1)
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