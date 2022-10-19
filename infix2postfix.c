#include <stdio.h>
#include <ctype.h>
#include <math.h>

char Stack[30];
int top=-1;
void push(char);
char pop();
int priority(char);


int main(){
	
	char infix[30],postfix[30];
	char *in,*post,x,y;
	printf("Enter the Infix Expression : ");
	scanf("%s",infix);
	in=infix;
	post=postfix;
	
	while((x=*in)!='\0'){
	
		if (x=='(')
			push(x);
		else if (isalnum(x)){
		
			*post=x;
			post++;
		}
		else if (x==')'){
		
			while((y=pop())!='('){
				
				*post=pop();
				post++;		
			}
				
		}
		
		else{
		
			if (priority(x)>priority(Stack[top]))
				push(x);
			else{
			
				while(priority(x)<=priority(Stack[top])){
				
					*post=pop();
					post++;
						
				}
				push(x);			
			}		
		}
	in++;
	}
	
	while(top!=-1){
	
		*post=pop();
		post++;

	}
	
	printf("Postfix Expression is %s ",postfix);

  
	return 0;
}

void push(char x){
	
	Stack[++top]=x;

}

char pop(){

	if (top==-1)
		return -1;
	return Stack[top--];

}

int priority(char x){

	if (x=='(')
		return 0;
	else if (x=='+' || x=='-')
		return 1;
	else if (x=='*' || x=='/')
		return 2;
	else if (x=='^')
		return 3;

}
