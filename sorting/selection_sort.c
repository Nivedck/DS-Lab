#include <stdio.h>



void selection_sort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        int min=i,index;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
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

    printf("\nSelection Sort in Progress....\n");
    selection_sort(arr,n);

    printf("Sorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
