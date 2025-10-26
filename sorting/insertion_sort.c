#include <stdio.h>



void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insertion_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(&arr[j-1],&arr[j]);
            j--;
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

    printf("\nInsertion Sort in Progress....\n");
    insertion_sort(arr,n);

    printf("Sorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
