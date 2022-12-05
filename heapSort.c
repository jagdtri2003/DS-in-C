#include<stdio.h>
#define n 8
int a[n+1],heap_size=n;

void heapify(int i);
void build_max_heap();
void heapSort();

int main(){
	int i;
	printf("Enter the elements : \n");
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	heapSort();
	
	printf("Sortest List is : \n");
	for (i=1;i<=n;i++)
		printf("%d\t",a[i]);
		
	return 0;
}


void build_max_heap(){

	int i;
	for(i=n/2;i>=1;i--){
		heapify(i);
	}
}

void heapSort(){

	int temp;
	build_max_heap();
	
	while(heap_size!=0){
	
		temp=a[1];
		a[1]=a[heap_size];
		a[heap_size--]=temp;
		heapify(1);
	
	}	

}

void heapify(int i){

	int left,right,max,temp;
	
	left=2*i;
	right=2*i+1;
	
	if (left <=heap_size && a[left]>a[i]){
		max=left;
	}
	else{
		max=i;
	}
	if (right <=heap_size && a[right]>a[max]){
		max=right;
	}
	if (max!=i){
		temp=a[max];
		a[max]=a[i];
		a[i]=temp;
		heapify(max);
	}

}
