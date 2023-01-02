#include <stdio.h>
#include <stdbool.h>
#define n 7

int adj[n+1][n+1];
bool visited[n+1];

void adj_matrix();
void BFS(int);
void DFS(int);

int main(){

	int start;
	printf("\nEnter the Adjacency Matrix : \n");
	adj_matrix();
	printf("Enter the Start Node : ");
	scanf("%d",&start);
	printf("BFS Traversal of the graph is : ");
	BFS(start);
	printf("Enter the Start Node : ");
	scanf("%d",&start);
	for(int j=1;j<=n;j++)
		visited[j]=false;
	printf("DFS Traversal of the graph is : ");
	DFS(start);
	
	return 0;
}

void adj_matrix(){

	int max=n*(n-1)/2,i,start,dest;
	for (i=1;i<=max;i++){
		printf("Enter the Start and End Point of the Vertex (0 0 to exit ) : ");
		scanf("%d%d",&start,&dest);
		
		if (start==0  && dest==0 ){
			break;
		}
		if (start <0 || dest <0 ){
			printf("Enter a valid input !! ");
			i--;
			continue;
		}
		adj[start][dest]=1;
	
	}
}

void BFS(int start){

	int Queue[n];
	int front=0,rear=0,u;
	Queue[rear]=start;
	
	for(int j=1;j<=n;j++)
		visited[j]=false;
	
	while(front<=rear){
		u=Queue[front++];
		visited[u]=true;
		printf("%d\t",u);
		for (int i=1;i<=n;i++){
			if (adj[u][i]==1 && visited[i]==false){
				Queue[++rear]=i;
				visited[i]=true;
			}
		}
	}
}


void DFS(int start){

	visited[start]=true;
	printf("%d\t",start);
	for (int i=1;i<=n;i++){
		if (adj[start][i]==1 && visited[i]==false)
			DFS(i);
	
	}

}
