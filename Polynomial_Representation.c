//Polynomial Representation
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct poly {
	float coef;
	int exp;
	struct poly *next;
}node;

void createPoly(node *l){
	char ch;
	while(1){
		printf("\n Enter coeficient & power:");
		scanf("%f%d",&l->coef,&l->exp);
		printf("\n Another term (y/n):");
		ch = getch(); //taking single character input
		if(ch == 'n' || ch == 'N'){
			l->next = NULL;
			break;
		}
		l->next = (node *)malloc(sizeof(node));
		l = l->next;
	}
}

void displayPoly(node *l){
	while(l!=NULL){
		printf("%f X^ %d + ",l->coef, l->exp);
		l = l->next;
	}
}

int main(){
	node *h;
	char ch;
	int x;
	h = (node *)malloc(sizeof(node));
	while(1){
		printf("\n Press 1 to create a polynomial");
		printf("\n Press 2 to display a polynomial");
		printf("\n Press 3 to add two polynomials");
		printf("\n Press 4 to exit");
		scanf("%d",&x);
		switch(x){
			case 1:	
					createPoly(h);
					break;
			case 2:	
					displayPoly(h);
					break;
			case 3:	
					;
					break;
			case 4:
					exit(0);
		}
	}
}