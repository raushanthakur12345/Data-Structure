//Double Ended Queue implementation using Array
#include<stdio.h>
#include<stdlib.h>
#define MAX 6

int DQ[MAX];
int front = 0;
int rear = -1;

void rearAdd(int x){
	if(rear == MAX-1){
		printf("\n Queue is Full");
		return;
	}
	rear = rear + 1;
	DQ[rear] = x; 
}

int frontDel(){
	int x;
	if(front > rear){
		printf("\n Queue is Empty");
		return -1;
	}
	x = DQ[front];
	front = front + 1; 
	return x;
}

void frontAdd(int x){
	if(front == 0){
		printf("\n Insertion at front end is not possible");
		return;
	}
	front--;
	DQ[front] = x;
}

int rearDel(){
	int x;
	if(front > rear){
		printf("\n Queue is Empty");
		return -1;
	}
	x = DQ[rear];
	rear = rear - 1;
	return x;
}

void showQueue(){
	if(front > rear)
		printf("\n Queue is empty");
	else {
		printf("\n Current Status of Queue:");
		for(int i=front;i<=rear;i++){
			printf("%d ",DQ[i]);
		}
	}
}
int main(){
	int x,v;
	while(1){
		printf("\n Press 1 to insert at rear end");
		printf("\n Press 2 to delete from front end");
		printf("\n Press 3 to insert at front end");
		printf("\n Press 4 to delete from rear end");
		printf("\n Press 5 to show the Queue");
		printf("\n Press 6 to exit");
		scanf("%d",&x);
		switch(x){
			case 1:
					printf("\n Enter a value to be inserted:");
					scanf("%d",&v);
					rearAdd(v);
					break;
			case 2:
					v = frontDel();
					if(v != -1)
						printf("\n The deleted element is %d",v);
					break;
			case 3:
					printf("\n Enter a value to be inserted:");
					scanf("%d",&v);
					frontAdd(v);
					break;
			case 4:
					v = rearDel();
					if(v != -1)
						printf("\n The deleted element is %d",v);
					break;
					
			case 5:
					showQueue();
					break;
			case 6:
					exit(0);
		}
	}
}