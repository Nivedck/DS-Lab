#include <stdio.h>

#define MAX 100

// Function to read a matrix
void readMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to convert a matrix to sparse form
int convertToSparse(int mat[MAX][MAX], int rows, int cols, int sparse[MAX][3]) {
    int k = 1; // Index for sparse matrix
    sparse[0][0] = rows;
    sparse[0][1] = cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }

    sparse[0][2] = k - 1; // Number of non-zero elements
    return k; // Total number of rows in sparse matrix
}

// Function to display a sparse matrix
void displaySparse(int sparse[MAX][3]) {
    int terms = sparse[0][2];
    printf("\nRow\tCol\tValue\n");
    for (int i = 0; i <= terms; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

// Function to transpose a sparse matrix
void transposeSparse(int sparse[MAX][3], int transpose[MAX][3]) {
    int terms = sparse[0][2];
    transpose[0][0] = sparse[0][1]; // Rows become columns
    transpose[0][1] = sparse[0][0];
    transpose[0][2] = terms;

    int k = 1;
    for (int col = 0; col < sparse[0][1]; col++) {
        for (int i = 1; i <= terms; i++) {
            if (sparse[i][1] == col) {
                transpose[k][0] = sparse[i][1];
                transpose[k][1] = sparse[i][0];
                transpose[k][2] = sparse[i][2];
                k++;
            }
        }
    }
}

// Function to add two sparse matrices
int addSparse(int s1[MAX][3], int s2[MAX][3], int sum[MAX][3]) {
    if (s1[0][0] != s2[0][0] || s1[0][1] != s2[0][1]) {
        printf("Matrix dimensions do not match! Cannot add.\n");
        return 0;
    }

    int t1 = s1[0][2], t2 = s2[0][2];
    sum[0][0] = s1[0][0];
    sum[0][1] = s1[0][1];

    int i = 1, j = 1, k = 1;
    while (i <= t1 && j <= t2) {
        if (s1[i][0] < s2[j][0] ||
           (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1])) {
            sum[k][0] = s1[i][0];
            sum[k][1] = s1[i][1];
            sum[k][2] = s1[i][2];
            i++; k++;
        }
        else if (s2[j][0] < s1[i][0] ||
                (s1[i][0] == s2[j][0] && s2[j][1] < s1[i][1])) {
            sum[k][0] = s2[j][0];
            sum[k][1] = s2[j][1];
            sum[k][2] = s2[j][2];
            j++; k++;
        }
        else {
            sum[k][0] = s1[i][0];
            sum[k][1] = s1[i][1];
            sum[k][2] = s1[i][2] + s2[j][2];
            i++; j++; k++;
        }
    }

    // Remaining elements
    while (i <= t1) {
        sum[k][0] = s1[i][0];
        sum[k][1] = s1[i][1];
        sum[k][2] = s1[i][2];
        i++; k++;
    }
    while (j <= t2) {
        sum[k][0] = s2[j][0];
        sum[k][1] = s2[j][1];
        sum[k][2] = s2[j][2];
        j++; k++;
    }

    sum[0][2] = k - 1;
    return k;
}

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX];
    int sparse1[MAX][3], sparse2[MAX][3];
    int transpose1[MAX][3];
    int sum[MAX][3];

    int rows, cols;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("\nMatrix 1:\n");
    readMatrix(mat1, rows, cols);
    printf("\nMatrix 2:\n");
    readMatrix(mat2, rows, cols);

    int t1 = convertToSparse(mat1, rows, cols, sparse1);
    int t2 = convertToSparse(mat2, rows, cols, sparse2);

    printf("\nSparse form of Matrix 1:");
    displaySparse(sparse1);
    printf("\nSparse form of Matrix 2:");
    displaySparse(sparse2);

    transposeSparse(sparse1, transpose1);
    printf("\nTranspose of Sparse Matrix 1:");
    displaySparse(transpose1);

    int tsum = addSparse(sparse1, sparse2, sum);
    if (tsum != 0) {
        printf("\nSum of Sparse Matrices:");
        displaySparse(sum);
    }

    return 0;
}
