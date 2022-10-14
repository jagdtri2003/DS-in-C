#include <stdio.h>
#define inf 9999

void merge_sort(int arr[],int p,int r);
void merge(int arr[],int p,int q,int r);

int main(){

    int n,i;
    printf("Enter the number of terms : " );
    scanf("%d",&n);
    int a[n];

    for (i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }

    merge_sort(a,0,n-1);

    printf("After Sorting : ");
    for (i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}

void merge_sort(int arr[],int p,int r){
    if (p<r){
        int q=(p+r)/2;
        merge_sort(arr,p,q);
        merge_sort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

void merge(int arr[],int p,int q,int r){

    int n1,n2,i,j,k;

    n1=q-p+1;
    n2=r-p;

    int L[n1],R[n2];

    for (i=0;i<n1;i++){
        L[i]=arr[p+i];
        //printf("%d ",L[i]);
    }

    for (j=0;j<n1;j++){
        R[j]=arr[q+j+1];
    }
    L[n1]=inf;
    R[n2]=inf;
    i=0;
    j=0;

    for (k=p;k<=r;k++){
        if (L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
    }
}