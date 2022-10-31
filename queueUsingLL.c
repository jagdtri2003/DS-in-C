#include <stdio.h>
#include <malloc.h>

struct Queue{
	int data;
	struct Queue *next;
}*Start=NULL,*Rear=NULL;

typedef struct Queue queue;

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
	
	queue * new_node = (queue *)malloc(sizeof(queue));
	new_node->next=NULL;
	new_node->data=key;
	if (Start==NULL){
		Start=new_node;
		Rear=new_node;
		return;
	}
	Rear->next=new_node;
	Rear=new_node;
	
}

int dequeue(){

	queue *temp;
	int key;
	if (Start==NULL){
	
		printf("UNDERFLOW !!\n");
		return -1;
	}
		
	if (Start==Rear){   			//SINGLE ELEMENT 
		temp=Start;
		key=Start->data;
		Start=NULL;
		Rear=NULL;
		free(temp);
		return key;
	}
	temp=Start;
	key=temp->data;
	Start=Start->next;
	free(temp);
	return key;
}


