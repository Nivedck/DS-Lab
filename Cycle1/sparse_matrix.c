#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Term;

void printSparse(Term a[], int n) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
}

int createSparse(int matrix[10][10], int row, int col, Term sparse[]) {
    int k = 1;
    sparse[0].row = row;
    sparse[0].col = col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
    sparse[0].value = k - 1;
    return k;
}

void transpose(Term a[], Term result[]) {
    int k = 1;
    result[0].row = a[0].col;
    result[0].col = a[0].row;
    result[0].value = a[0].value;

    for (int i = 0; i < a[0].col; i++) {
        for (int j = 1; j <= a[0].value; j++) {
            if (a[j].col == i) {
                result[k].row = a[j].col;
                result[k].col = a[j].row;
                result[k].value = a[j].value;
                k++;
            }
        }
    }
}

int main() {
    int mat1[10][10], r, c;
    Term sparse1[MAX], trans[MAX];

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);
    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat1[i][j]);

    int size = createSparse(mat1, r, c, sparse1);
    printf("\nSparse Matrix:\n");
    printSparse(sparse1, size);

    transpose(sparse1, trans);
    printf("\nTranspose Sparse Matrix:\n");
    printSparse(trans, size);

    return 0;
}
