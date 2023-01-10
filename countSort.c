#include<stdio.h>

void CountSort(int A[],int k);
int size=12;
int B[13];


int main(){

	/*
	int k,i;
	printf("Enter the value of K : ");
	scanf("%d",&k);
	printf("\nEnter the values of Array : ");
	for (i=0;i<)
	scanf("%d",&k);
	*/
	int A[]={2,1,0,5,4,3,1,0,2,4,5,3};
	CountSort(A,5);

	return 0;
}

void CountSort(int A[],int k){

	int C[k+1],i,j;
	
	for (i=0;i<=k;i++){
		C[i]=0;
	}
	for (j=0;j<size;j++){
		C[A[j]]+=1;
	}
	for (i=1;i<=k;i++){
		C[i]+=C[i-1];
	}
	for (j=size-1;j>=0;j--){
		B[C[A[j]]]=A[j];
		C[A[j]]-=1;
	}
	printf("Sorted Array :\n");
	for (int i=1;i<=12;i++)
		printf("%d  ",B[i]);
	
}
