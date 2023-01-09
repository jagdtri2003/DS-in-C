#include <stdio.h>
#include <stdbool.h>
#define n 6

int adj[n+1][n+1],stack[n],top=-1;
bool visited[n+1];

void adj_matrix();
void topological_sort(int);

int main(){
    int i;
    printf("Enter the Edges : \n");
    for(i=1;i<=n;i++)
        visited[i]=false;
    adj_matrix();
    for(i=1;i<=n;i++){
        if (visited[i]==false){
            topological_sort(i);
        }
    }
    printf("Topological Order is : \n");
    while(top>=0){
        printf("%d\t",stack[top--]);
    }    
    return 0;
}

void adj_matrix(){
    int s,d,i,max=n*(n-1)/2;

    for(i=1;i<=max;i++){
        printf("Enter the start and end point (0 0 to exit) : ");
        scanf("%d%d",&s,&d);
        if (s==0 && d==0)
            break;
        else if (s<0 || d<0){
            printf("Invalid Edge !!");
            i--;
            continue;
        }
        adj[s][d]=1;

    }
}

void topological_sort(int start){
    int i;
    visited[start]=true;
    for(i=1;i<=n;i++){
        if (adj[start][i]==1 && visited[i]==false){
            topological_sort(i);
        }
    }
    stack[++top]=start;
}