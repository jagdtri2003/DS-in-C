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
        if (!isdigit(z)){
            x=pop();
            y=pop();
            push(solve(x,y,z));
        }
        else
            push(((int)z)-48);
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
		return NULL;
	return Stack[top--];

}
int solve(int x,int y,char z){
    if (z=='+')
        return y+x;
    else if (z=='-')
        return y-x;
    else if (z=='*')
        return y*x;
    else if (z=='/')
        return y/x;
    else if (z=='^')
        return pow(y,x);
}