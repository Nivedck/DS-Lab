#include <stdio.h>
#include <stdlib.h>

//LINEAR SEARCH -- Nivedck

//ALGORITHM
//1 . Read array size
//2.  Read Array elements
//3.  Read the key element to search
//4.  Traverse over the array
//5. Match every element with the key 
//6. Return if found 
//7. Else return -1
//8. Print result

//Program

int linear_search(int arr[],int n, int key){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[100],n,key,i,result;
    printf("Enter Array Size : ");
    scanf("%d",&n);
    printf("\n");

    for(i=0;i<n;i++){
        printf("Enter Element %d :",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n");

    printf("Enter Element to search : ");
    scanf("%d",&key);

    result = linear_search(arr,n,key);

    if(result==-1){
        printf("Element Not Found! \n");
    }else{
        printf("Element Found at Index %d ",result);
    }

    return 0;

}