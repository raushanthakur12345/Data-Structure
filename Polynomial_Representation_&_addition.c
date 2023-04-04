//Polynomial Representation and Addition
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

node *addPoly(node *poly1, node *poly2, node *poly3){
	node *p1,*p2,*p3;
	p1 = poly1; p2=poly2; p3=poly3;
	while(p1!=NULL && p2!=NULL){
		if(p1->exp == p2->exp){
			p3->coef = p1->coef + p2->coef;
			p3->exp = p1->exp;
			p1 = p1->next;
			p2 = p2->next;
		}
		else if(p1->exp > p2->exp){
			p3->coef = p1->coef;
			p3->exp = p1->exp;
			p1 = p1->next;
		}
		else {
			p3->coef = p2->coef;
			p3->exp = p2->exp;
			p2 = p2->next;
		}
		p3->next = (node *) malloc(sizeof(node));
		p3 = p3->next;
	}
	while(p1!=NULL){
		p3->coef = p1->coef;
		p3->exp = p1->exp;
		p1 = p1->next;
		
		p3->next = (node *) malloc(sizeof(node));
		p3 = p3->next;
	}
	
	while(p2!=NULL){
		p3->coef = p2->coef;
		p3->exp = p2->exp;
		p2 = p2->next;

		p3->next = (node *) malloc(sizeof(node));
		p3 = p3->next;
	}
	p3->next = NULL;
}
void displayPoly(node *l){
	while(l->next!=NULL){
		printf("%.2f X^ %d + ",l->coef, l->exp);
		l = l->next;
	}
}

int main(){
	node *p1,*p2,*p3;
	char ch;
	int x;
	p1 = (node *)malloc(sizeof(node));
	p2 = (node *)malloc(sizeof(node));
	p3 = (node *)malloc(sizeof(node));
	while(1){
		printf("\n Press 1 to create a polynomial");
		printf("\n Press 2 to display a polynomial");
		printf("\n Press 3 to add two polynomials");
		printf("\n Press 4 to exit");
		scanf("%d",&x);
		switch(x){
			case 1:	
					createPoly(p1);
					break;
			case 2:	
					displayPoly(p1);
					break;
			case 3:	
					printf("\n Enter Polynomial 1");
					createPoly(p1);
					printf("\n Enter Polynomial 2");
					createPoly(p2);
					addPoly(p1,p2,p3);
					displayPoly(p3);
					break;
			case 4:
					exit(0);
		}
	}
}