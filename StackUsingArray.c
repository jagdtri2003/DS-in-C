#include <stdio.h>
#include <stdbool.h>
#define Max 10

void push(int data);
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
            pop();
            break;
        case 3:
            printf("Enter the value : ");
            scanf("%d",&key);
            push(key);
            break;
        case 4:
            printf("Enter the value : ");
            scanf("%d",&key);
            push(key);
            break;
        case 5:
            printf("Enter the value : ");
            scanf("%d",&key);
            push(key);
            break;       
        default:
            printf("Invalid input !!");
            break;
        }
        printf("Do you want to continue(0/1) :");
        scanf("%d",&cnt);
    }while(cnt);



    return 0;
}