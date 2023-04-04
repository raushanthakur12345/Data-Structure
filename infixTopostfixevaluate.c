#include<stdio.h>
#include<math.h>
#define MAX 20

float stack[MAX];
int top=-1;
void push(float v){
	if(top == MAX-1){
		printf("\n Stack is Full");
		return;
	}
	stack[++top] = v;
}

float pop(){
	float ch;
	if(top == -1){
		printf("\n Stack is Empty");
		return -1;
	}
	ch = stack[top--];
	return ch;
}

void evaluatePostfixExpression(char postfix[], float value[]){
	char ch,t;
	int i=0,j=0;
	float op1,op2;
	while(postfix[i]!='\0'){
		ch = postfix[i];
		if(ch >= 65 && ch<=90){
			push(value[i]);
		}
		else {
			op2 = pop();
			op1 = pop();
			switch(ch){
				case '^':
							push(pow(op1,op2));
							break;
				case '/':	push(op1/op2);
							break;
				case '*':	push(op1*op2);
							break;
				case '+':	push(op1+op2);
							break;
				case '-':	push(op1-op2);
							break;
			}
		}
		i++;
	}
	float result = pop();
	printf("\n Result = %f",result);
}

int main(){
	char postfix[50], ch;
	float value[50],x;
	int i=0,j=0;
	printf("\n Enter a valid postfix expression within:");
	gets(postfix);
	while(postfix[i] !='\0'){
		ch = postfix[i];
		if(ch >= 65 && ch<=90){
			printf("\n Enter value for %c:",ch);
			scanf("%f",&x);
			value[i] = x;
		}
		i++;
	}
	evaluatePostfixExpression(postfix,value);
	return 0;
}