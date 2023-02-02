#include <stdio.h>

void selectionSort(int[],int);

int main(){
    int n,i;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements : ");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    selectionSort(arr,n);

    printf("Sorted Array : ");

    for (i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

void selectionSort(int arr[],int n){
    int i,j,min_idx,temp;

    for(i=0;i<n;i++){
        min_idx=i;
        for(j=i+1;j<n;j++){
            if (arr[min_idx]>arr[j]){
                min_idx=j;
            }
        }
        if(min_idx!=i){
            temp=arr[i];
            arr[i]=arr[min_idx];
            arr[min_idx]=temp;
        }
    }
}