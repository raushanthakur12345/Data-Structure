#include<stdio.h>
#define MAX 20

char stack[MAX];
int top=-1;
void push(char ch){
	if(top == MAX-1){
		printf("\n Stack is Full");
		return;
	}
	stack[++top] = ch;
}

char pop(){
	char ch;
	if(top == -1){
		printf("\n Stack is Empty");
		return -1;
	}
	ch = stack[top--];
	return ch;
}

int preced(char op){
	if(op == '^')
		return 3;
	else if(op == '/' || op == '*')
		return 2;
	else if(op == '+' || op == '-')
		return 1;
	else
		return 0;
}

void convertInfixToPostfix(char infix[]){
	char postfix[50], ch,t;
	int i=0,j=0;
	while(infix[i]!='\0'){
		ch = infix[i];
		switch(ch){
			case '(':
						push(ch);
						break;
			case ')':	t = pop();
						while(t != '('){
							postfix[j++] = t;
							t = pop();
						}
						break;
			case '^':
			case '/':
			case '*':
			case '+':
			case '-':
						while(preced(ch) <= preced(stack[top])){
							postfix[j++] = pop();
						}
						push(ch);
						break;
			default:
						postfix[j++] = ch;
		}
		i++;
	}
	postfix[j] = '\0';
	printf("\n Postfix expression = %s",postfix);
}

int main(){
	char infix[50];
	printf("\n Enter an infix expression within ():");
	gets(infix);
	convertInfixToPostfix(infix);
	return 0;
}