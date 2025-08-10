#include <stdio.h>
#define MAX 100

typedef struct{
    int row;
    int col;
    int val;
}sparse_matrix;

int main(){

    sparse_matrix sm1[MAX];
    sparse_matrix sm2[MAX];

    int size1,size2,i,j;

    printf("Enter number of non zero elements in first matrix");
    scanf("%d",&size1);

    printf("Enter in the format Row,column,Value : \n");
    for(int i=1;i<=size1+1;i++){
        scanf("%d %d %d",&sm1[i].row , &sm1[i].col , &sm1[i].val);
    }

    printf("Enter number of non zero elements in second matrix : \n");
    scanf("%d",&size2);

    printf("Enter in the format Row,column,Value : \n");
    for(int i=1;i<=size1+1;i++){
        scanf("%d %d %d",&sm1[i].row , &sm1[i].col , &sm1[i].val);
    }

    sparse_matrix res[size1+size2+1];

    i=1;
    j=1;
    int k=1;

    while(i<size1 && j<size2){

        
        if(sm1[i].row==sm2[j].row && sm1[i].col ==) sm2[j].col ){
            res[k].row=i;
            res[k].col=i;
            res[k].val= sm1[i].val + sm2[j].val;
        }

    }

    






}