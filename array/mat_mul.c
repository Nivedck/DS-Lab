#include <stdio.h>

int main(){

    int A[3][3],B[3][3],C[2][2],i,j,k;
    int n=3;

    printf("Enter Matrix 1 Elements: \n");
    for(i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("Enter Element %d : ",i*n+j+1);
            scanf("%d",&A[i][j]);
        }
    }
    
    printf("Enter Matrix 2 Elements: \n");
    for(i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("Enter Element %d : ",i*n+j+1);
            scanf("%d",&B[i][j]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            C[i][j]=0;
            for(k=0;k<n;k++){
                C[i][j]+=A[k][j]*B[i][k];
            }
        }
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",C[i][j]);
        }
    }
    
}
