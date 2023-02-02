#include <stdio.h>
#define n 5

void make_set(int);
void Union(int,int);
void link(int,int);
int find_set(int);

int start[20],end[20],weight[20],parent[n+1],rank[n+1],A[20];

int main(){

	int i,s,e,w,j,temp,edges=0,total_weight=0;
	int max=n*(n-1)/2;
	for(i=1;i<=max;i++){
	
		printf("\nEnter the start,end & weight (0 0 0 to exit): ");
		scanf("%d%d%d",&s,&e,&w);
		if (s==0 && e==0)
			break;
		else if (s<0 || e<0){
			printf("\nInvalid Edge !!");
			i--;
			continue;
		}
		start[i]=s;
		end[i]=e;
		weight[i]=w;
		edges++;
	}
	
	for(i=1;i<=n;i++)
		make_set(i);
	
	for(i=1;i<=edges-1;i++){
		for (j=1;j<=edges-i;j++){
		
			if (weight[j]>weight[j+1]){
			
				temp=weight[j];
				weight[j]=weight[j+1];
				weight[j+1]=temp;
				temp=start[j];
				start[j]=start[j+1];
				start[j+1]=temp;
				temp=end[j];
				end[j]=end[j+1];
				end[j+1]=temp;
			}
		}
	}
	j=1;
	for(i=1;i<=edges;i++){
		if(find_set(start[i])!=find_set(end[i])){
			A[j++]=i;
			Union(start[i],end[i]);
		}
	}
	printf("The MST os :\n");
	for(i=1;i<j;i++){
		printf("\nEdge (%d,%d) with weight %d \n",start[A[i]],end[A[i]],weight[A[i]]);
		total_weight+=weight[A[i]];
	}
	printf("\nTotal Cost is : %d\n",total_weight);
	
	return 0;	
}

void make_set(int x){
	parent[x]=x;
	rank[x]=0;
}

void Union(int x,int y){
	link(find_set(x),find_set(y));
}

void link(int x,int y){
	if (rank[x]>rank[y])
		parent[y]=x;
	else{
		parent[x]=y;
		if (rank[x]==rank[y])
			rank[y]++;
	}
}

int find_set(int x){
	if(x!=parent[x])
		parent[x]=find_set(parent[x]);
	return parent[x];
}
