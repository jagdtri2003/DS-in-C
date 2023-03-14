//Implementation of Counting Sort
#include<stdio.h>
#define n 12
#define k 5
int main(){
	int a[n],c[k+1],b[n+1],i;
	printf("\nEnter the elements of array:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<=k;i++)
		c[i]=0;
	for(i=0;i<n;i++)//counting
		c[a[i]]+=1;
	for(i=1;i<=k;i++)
		c[i]=c[i]+c[i-1];
	for(i=n-1;i>=0;i--){
		b[c[a[i]]]=a[i];
		c[a[i]]--;
		}
	printf("\nThe sorted list is:\n");
	for(i=1;i<=n;i++)
		printf("%d\t",b[i]);
	return 0;
}
