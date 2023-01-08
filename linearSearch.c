#include <stdio.h>

int main(){

    int i,size,ele,found=0;
    printf("Enter the size of Array : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter elements : ");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);

    printf("Enter the element to be searched : ");
    scanf("%d",&ele);
    
    for(i=0;i<size;i++){
        if (arr[i]==ele){
            found=i+1;
            break;
        }
    }
    if (found){
        printf("Element is found at %d",found);
    }
    else{
        printf("Element not found !!");
    }
    return 0;
}

