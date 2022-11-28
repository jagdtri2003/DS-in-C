#include <stdio.h>
#define n 10

int main(){

	int a[n],bin[10][5],count[10];
	int i,j,k,m,rem,divisor=1,max,digit=0;
	
	printf("Enter the Elements of the array :\n");
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	//Determining Max Element 
	max=a[0];
	for (i=1;i<n;i++)
		if (max<a[i])
			max=a[i];
			
	
	//Determining Digits in Max Element 
	while(max!=0){
		digit++;
		max/=10;
	}
	
	while(digit!=0){
	
		for(i=0;i<n;i++)
			count[i]=0;	
		for (i=0;i<n;i++){
			rem=(a[i]/divisor)%10;
			bin[rem][count[rem]++]=a[i];
		}
		m=0;
		for (j=0;j<10;j++){
			if (count[j]>0){
				for (k=0;k<count[j];k++)
					a[m++]=bin[j][k];
			
			}
		
		}
	
		digit--;
		divisor*=10;
	}
	printf("Sorted array :\n");
	for (i=0;i<n;i++)
		printf("%d\t",a[i]);
	
	

	return 0;
}
