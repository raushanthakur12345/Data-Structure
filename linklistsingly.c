//Single linked list creation and display
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct link {
	int data;
	struct link *next;
}node;

void createSLL(node *l){
	char ch;
	while(1){
		printf("\n Enter data:");
		scanf("%d",&l->data);
		printf("\n Another node (y/n):");
		ch = getch(); //taking single character input
		if(ch == 'n' || ch == 'N'){
			l->next = NULL;
			break;
		}
		l->next = (node *)malloc(sizeof(node));
		l = l->next;
	}
}

void displaySLL(node *l){
	while(l!=NULL){
		printf("%d ",l->data);
		l = l->next;
	}
}

node *getNewNode(){
	node *new1 = (node *)malloc(sizeof(node));
	printf("\n Enter data for the new node:");
	scanf("%d",&new1->data);
	return new1;
}

node *insertBeforeFirstNode(node *h){
	node *n1 = getNewNode();
	n1->next = h;
	return n1;// h = n1;
}

node *findNode(node *l, int v){
	while(l->data !=v && l!=NULL){
		l = l->next;
	}
	return l;
}	
		
node *insertAfterSpecificNode(node *h){
	int v;
	printf("\n Enter data value of a node after which you want to insert:");
	scanf("%d",&v);
	node *l = findNode(h,v);
	if(l == NULL){
		printf("\n Node does not exist");
		return h;
	}
	node *n1 = getNewNode();
	n1->next = l->next;
	l->next = n1;
	return h;
}
				
node *insertAfterLastNode(node *h){
	node *l = h;
	while(l->next!=NULL){
		l = l->next;
	}
	node *n1 = getNewNode();
	n1->next = l->next;
	l->next = n1;
	return h;
}
					
node *insert(node *h){
	int x;
	while(1){
		printf("\n Press 1 to insert a new node before the 1st node");
		printf("\n Press 2 to insert a new node after a specific node");
		printf("\n Press 3 to insert a new node after the last node");
		printf("\n Press 4 to go to the previous menu");
		scanf("%d",&x);
		switch(x){
			case 1:
					h = insertBeforeFirstNode(h);
					break;
			case 2:
					h = insertAfterSpecificNode(h);
					break;
			case 3:
					h = insertAfterLastNode(h);
					break;
			case 4:
					return h;
		}
	}
}

int main(){
	node *h;
	char ch;
	int x;
	h = (node *)malloc(sizeof(node));
	while(1){
		printf("\n Press 1 to create a linked list");
		printf("\n Press 2 to display a linked list");
		printf("\n Press 3 to insert a new node");
		printf("\n Press 4 to exit");
		scanf("%d",&x);
		switch(x){
			case 1:	
					createSLL(h);
					break;
			case 2:	
					displaySLL(h);
					break;
			case 3:	
					h = insert(h);
					break;
			case 4:
					exit(0);
		}
	}
}