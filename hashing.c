#include <stdio.h>
#define n 6
int a[n];

int main(){

	int i,key,col,ele;
	for (i=0;i<n;i++)
		a[i]=0;
	printf("Enter the Elements : \n");
	for (i=0;i<n;i++){
		col=0;
		scanf("%d",&key);
		
		//Linear Probing 
		 
		while (a[(key + col)%n]){
			col++;
		}
		a[(key + col)%n]=key;
	}
	
	printf("The Hash Table is  :\n");
	for (i=0;i<n;i++)
		printf("%d\t",a[i]);
	

	return 0;
}
