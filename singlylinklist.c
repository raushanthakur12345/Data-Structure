//Single linked list creation and display
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct link {
	int data;
	struct link *next;
}node;

int main(){
	node *h, *l;
	char ch;
	h = (node *)malloc(sizeof(node));
	l = h;
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
	printf("\n List is:");
	l = h;
	while(l!=NULL){
		printf("%d ",l->data);
		l = l->next;
	}
	return 0;	
	
}