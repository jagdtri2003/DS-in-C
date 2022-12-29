#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

struct Stack{
    int data;
    struct Stack *next;
}*START=NULL;

typedef struct Stack Stack;

void push(int);
int pop();
int peek();
bool isEmpty();

int main(){

    int ch,cnt,key;
    do{
        printf("1.Push \n2.Pop \n3.Peek \n4.isEmpty  \nEnter Your Choice : ");
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
    Stack * new_node =(Stack *)malloc(sizeof(Stack));
    new_node->next=START;
    new_node->data=key;
    START=new_node;
}

int pop(){
    if (isEmpty()){
        printf("Stack is empty !");
        return -1;
    }
    int key=START->data;
    Stack *temp=START;
    START=START->next;
    free(temp);
    return key;
}

int peek(){
    if (isEmpty()){
        printf("Stack is empty !");
        return -1;
    }
    return START->data;   

}

bool isEmpty(){
    if (START==NULL)
        return true;
    return false;
}
