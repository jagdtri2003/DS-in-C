#include <stdio.h>

int partition(int arr[],int lb,int ub);
void quickSort(int arr[],int lb,int ub);

int main(){
    int n,i;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements : ");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    quickSort(arr,0,n-1);

    printf("Sorted Array : ");

    for (i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}

int partition(int arr[],int lb,int ub){

    int x,i,j,temp;

    x=arr[ub];
    i=lb-1;

    for (j=lb;j<ub;j++){

        if (arr[j]<=x){
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[ub];
    arr[ub]=temp;

    return i+1;
}

void quickSort(int arr[],int lb,int ub){
    if (lb<ub){
        int q=partition(arr,lb,ub);
        quickSort(arr,lb,q-1);
        quickSort(arr,q+1,ub);
    }
}