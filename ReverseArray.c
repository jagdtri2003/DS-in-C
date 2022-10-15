//Reverse a array in C
#include <stdio.h>

void rev(int arr[],int n);

int main(){

    int arr[]={1,2,3,4,5,6};
    int n=6;
    rev(arr,n);

    for (int i=0;i<n;i++)
        printf("%d ",arr[i]);
    
}

void rev(int arr[],int n){
    for (int i=0;i<n/2;i++){
        int temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
}
