#include <stdio.h>
#define MAX 5

int queue[MAX],front=-1,rear=-1;

void enqueue(int);
int dequeue();

int main(){

	int key,choice,ch;
	do{
		printf("1.Insertion in queue \n2.Deletion in queue\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the key : ");
				scanf("%d",&key);
				enqueue(key);
				break;
			case 2:
				if ((key=dequeue())!=-1)
					printf("The Deleted Element is %d ",key);
				break;
			default:
				printf("Choose a valid option !! ");
		}
		printf("\nDo you want to continue ? (0/1) : ");
		scanf("%d",&ch);
	
	}while(ch);
	return 0;
}


void enqueue(int key){
	if (rear==MAX-1){
		printf("OVERFLOW !! \n");
		return ;
	}
	if (front==-1){
		front=0;
		rear=0;
		queue[front]=key;
		return;	
	}
	queue[++rear]=key;

}

int dequeue(){
	int key;
	if (front==-1){
		printf("UNDERFLOW !!\n");
		return -1;
	}	
	if (front==rear){
		key=queue[front--];
		rear--;
		return key;
	}
	return queue[front++];
}


