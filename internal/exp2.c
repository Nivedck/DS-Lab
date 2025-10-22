#include <stdio.h>
#include <stdlib.h>

// Question 2 - Polynomial -- Nivedck

//Algorithm
//
//1. initalize 3 polynomials using array of structures - poly1,poly2,result
//2. read the number of terms in the first polynomial and the terms
//3. read the number of terms in the second polynomial and the terms
//4. intialize 3 indices variables to zero . i, j, k .
//5. while there is elements left in both polynomials
//  repeat:
//  if(poly1[i].exp==poly2[j].exp){
//    result[k].coeff = poly1[i] + poly2[j];
//    result[k].exp = poly1[i].exp;
//    i++;
//    j++;
//    k++;
//    }
//  else if ( poly[i].exp>poly[j].exp) copy poly[i] to res[k] , k++ , i++;
// else copy poly[j] to res[k] , k++ , j++;
// copy remaining terms in the both polynomials to the result polynomial
//6. End


typedef struct Polynomial{
    int coeff;
    int exp;
}Polynomial;

void read_poly(int n, Polynomial poly[]){
    for(int i=0;i<n;i++){
        printf("Enter Coefficient of term %d: ",i+1);
        scanf("%d",&poly[i].coeff);
        printf("Enter Exponent of term %d: ",i+1);
        scanf("%d",&poly[i].exp);
    }
    printf("\n");
}

void print_poly(int n, Polynomial poly[]){
    for(int i=0;i<n;i++){
        printf("%dx^%d",poly[i].coeff , poly[i].exp);
        if(i!=n-1){
            printf("+");
        }
    }
}


int add_poly(Polynomial poly1[] , int n1 ,Polynomial poly2[],int n2 , Polynomial result[]){
    int i=0;
    int j=0;
    int k=0;

    while(i<n1 && j<n2){
        if(poly1[i].exp == poly2[j].exp){
            result[k].exp = poly1[i].exp;
            result[k].coeff = poly1[i].coeff + poly2[j].coeff;
            i++;
            j++;
            k++;
        }
        else if(poly1[i].exp > poly2[j].exp){
            result[k] = poly1[i];
            k++;
            i++;
        }
        else{
            result[k] = poly2[j];
            k++;
            j++;
        }
    }

        while( i <n1){
            result[k++]=poly1[i++];
        }

        while( j<n2){
            result[k++]=poly2[j++];
        }


    return k;
}

int main(){
    int n1,n2;

    Polynomial poly1[20],poly2[20],result[20];

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d" ,&n1);
    read_poly(n1,poly1);

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d" ,&n2);
    read_poly(n1,poly2);

    int res= add_poly(poly1,n2,poly2,n2,result);

    print_poly(res,result);

}
