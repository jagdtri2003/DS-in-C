#include <stdio.h>
#include <stdbool.h>
#define Max 10

void push(int);
int pop();
int peek();
bool isFull();
bool isEmpty();
int Stack[Max],top=-1;

int main(){

    int ch,cnt,key;
    do{
        printf("1.Push \n2.Pop \n3.Peek \n4.isEmpty \n5.isFull \nEnter Your Choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d",&key);
            push(key);
            break;
        case 2:
            key=pop();
            if (key!=-1)
                printf("Poped Element is %d ",key);
            break;
        case 3:
            key=peek();
            if (key!=-1)
                printf("Top Element is %d ",key);
            break;
        case 4:
            if (isEmpty())
                printf("Stack is empty ");
            else
                printf("Stack is not empty");
            break;
        case 5:
            if (isFull())
                printf("Stack is full ");
            else
                printf("Stack is not full");
            break;       
        default:
            printf("Invalid input !!");
            break;
        }
        printf("\nDo you want to continue(0/1) :");
        scanf("%d",&cnt);
    }while(cnt);

    return 0;
}

void push(int key){
    if (isFull()){
        printf("Stack is Full !");
        return;
    }
    top++;
    Stack[top]=key;
}

int pop(){
    if (isEmpty()){
        printf("Stack is Empty !");
        return -1;
    }
    int key=Stack[top];
    top--;
    return key;
}

int peek(){
    if (isEmpty()){
        printf("Stack is Empty !");
        return -1;
    }
    return Stack[top];
}
bool isFull(){
    if (top==Max-1)
        return true;
    return false;
}

bool isEmpty(){
    if (top==-1)
        return true;
    return false;
}