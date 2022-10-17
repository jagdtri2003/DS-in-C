#include <stdio.h>
#include <math.h>
#include <ctype.h>

int Stack[20];
int top=-1;

void push(char);
char pop();
int solve(int,int,char);

int main(){

    char postfix[20],*post,z;
    int x,y;
    printf("Enter expression in postfix : ");
    scanf("%s",postfix);
    post=postfix;
    while((z=*post)!='\0'){
        if (isdigit(z))
            push(((int)z)-48);
        else{
            x=pop();
            y=pop();
            push(solve(x,y,z));
        }   
        post++;
    }
    printf("Result is : %d",(int)pop());
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
int solve(int x,int y,char z){
    switch(z){
        case '+':
            return y+x;
        case '-':
            return y-x;
        case '*':
            return y*x;
        case '/':
            return y/x;
        case '^':
            return pow(y,x);
    }       
}