#include <stdio.h>

struct Term {
    int coeff;
    int exp;
};

void addPolynomials(struct Term a[], int m, struct Term b[], int n) {
    struct Term result[100];
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (a[i].exp > b[j].exp)
            result[k++] = a[i++];
        else if (a[i].exp < b[j].exp)
            result[k++] = b[j++];
        else {
            result[k].coeff = a[i].coeff + b[j].coeff;
            result[k].exp = a[i].exp;
            k++; i++; j++;
        }
    }

    while (i < m) result[k++] = a[i++];
    while (j < n) result[k++] = b[j++];

    printf("Resultant Polynomial: ");
    for (int x = 0; x < k; x++) {
        printf("%dx^%d", result[x].coeff, result[x].exp);
        if (x != k - 1) printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Term a[100], b[100];
    int m, n;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        printf("Enter coeff and exp for term %d: ", i+1);
        scanf("%d%d", &a[i].coeff, &a[i].exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and exp for term %d: ", i+1);
        scanf("%d%d", &b[i].coeff, &b[i].exp);
    }

    addPolynomials(a, m, b, n);

    return 0;
}
