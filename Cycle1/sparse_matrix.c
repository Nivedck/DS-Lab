#include <stdio.h>

#define MAX 50

// Function to convert sparse to normal matrix
void sparseToNormal(int sparse[MAX][3], int normal[MAX][MAX]) {
    int rows = sparse[0][0];
    int cols = sparse[0][1];
    int nonZero = sparse[0][2];

    // Initialize all elements to zero
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            normal[i][j] = 0;

    // Fill non-zero values
    for (int i = 1; i <= nonZero; i++) {
        int r = sparse[i][0];
        int c = sparse[i][1];
        int val = sparse[i][2];
        normal[r][c] = val;
    }
}

// Function to display normal matrix
void printNormalMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to add two sparse matrices
void addSparse(int s1[MAX][3], int s2[MAX][3], int sum[MAX][3]) {
    if (s1[0][0] != s2[0][0] || s1[0][1] != s2[0][1]) {
        printf("Addition not possible! Dimensions mismatch.\n");
        sum[0][2] = 0;
        return;
    }

    int i = 1, j = 1, k = 1;
    int r1 = s1[0][2], r2 = s2[0][2];

    sum[0][0] = s1[0][0];
    sum[0][1] = s1[0][1];

    while (i <= r1 && j <= r2) {
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
        else { // Same position
            sum[k][0] = s1[i][0];
            sum[k][1] = s1[i][1];
            sum[k][2] = s1[i][2] + s2[j][2];
            i++; j++; k++;
        }
    }

    // Copy remaining elements
    while (i <= r1) {
        sum[k][0] = s1[i][0];
        sum[k][1] = s1[i][1];
        sum[k][2] = s1[i][2];
        i++; k++;
    }
    while (j <= r2) {
        sum[k][0] = s2[j][0];
        sum[k][1] = s2[j][1];
        sum[k][2] = s2[j][2];
        j++; k++;
    }

    sum[0][2] = k - 1; // total non-zero elements
}

// Function to transpose a sparse matrix
void transposeSparse(int s[MAX][3], int t[MAX][3]) {
    int rows = s[0][0], cols = s[0][1], nonZero = s[0][2];
    t[0][0] = cols;
    t[0][1] = rows;
    t[0][2] = nonZero;

    int k = 1;
    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= nonZero; i++) {
            if (s[i][1] == col) {
                t[k][0] = s[i][1];
                t[k][1] = s[i][0];
                t[k][2] = s[i][2];
                k++;
            }
        }
    }
}

int main() {
    int s1[MAX][3], s2[MAX][3], sum[MAX][3], trans[MAX][3];
    int n1, n2;

    // Read first sparse matrix
    printf("Enter rows, cols and number of non-zero elements for Matrix 1: ");
    scanf("%d%d%d", &s1[0][0], &s1[0][1], &s1[0][2]);
    printf("Enter row, col, value for each non-zero element of Matrix 1:\n");
    for (int i = 1; i <= s1[0][2]; i++)
        scanf("%d%d%d", &s1[i][0], &s1[i][1], &s1[i][2]);

    // Read second sparse matrix
    printf("Enter rows, cols and number of non-zero elements for Matrix 2: ");
    scanf("%d%d%d", &s2[0][0], &s2[0][1], &s2[0][2]);
    printf("Enter row, col, value for each non-zero element of Matrix 2:\n");
    for (int i = 1; i <= s2[0][2]; i++)
        scanf("%d%d%d", &s2[i][0], &s2[i][1], &s2[i][2]);

    // Addition
    addSparse(s1, s2, sum);

    // Transpose of Matrix 1
    transposeSparse(s1, trans);

    // Convert to normal matrix & display
    int normal[MAX][MAX];

    printf("\nMatrix 1 in normal form:\n");
    sparseToNormal(s1, normal);
    printNormalMatrix(normal, s1[0][0], s1[0][1]);

    printf("\nMatrix 2 in normal form:\n");
    sparseToNormal(s2, normal);
    printNormalMatrix(normal, s2[0][0], s2[0][1]);

    printf("\nSum Matrix in normal form:\n");
    sparseToNormal(sum, normal);
    printNormalMatrix(normal, sum[0][0], sum[0][1]);

    printf("\nTranspose of Matrix 1 in normal form:\n");
    sparseToNormal(trans, normal);
    printNormalMatrix(normal, trans[0][0], trans[0][1]);

    return 0;
}
