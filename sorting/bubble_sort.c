#include <stdio.h>


void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){ 
        if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
        }
        }
    }
}

int main(){
    int arr[100],n;
    printf("Enter the size of array : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter Element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nBubble Sort in Progress....\n");
    bubble_sort(arr,n);

    printf("Sorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
