#include <stdio.h>

int linear_search(int arr[],int n , int target){
    
    int i;
    
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }
    }

    return -1;
}

int main(){
    
    int arr[50],n,key;
    printf("Enter Number of Elements : ");
    scanf("%d",&n);
    printf("\n");

    for(int i=0;i<n;i++){
        printf("Enter Element %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Enter Element to Search : ");
    scanf("%d",&key);

    int result=linear_search(arr,n,key);

    if(result==-1){
        printf("Element Not Found !");
    }else{
        printf("Element Found At Index : %d ",result);
    }

    

}
