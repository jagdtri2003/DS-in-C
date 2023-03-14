#include <stdio.h>

void insertionSort(int[],int);

int main(){
    int n,i;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements : ");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    insertionSort(arr,n);

    printf("Sorted Array : ");

    for (i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

void insertionSort(int arr[],int n){
    int i,j,temp;

    for(i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}