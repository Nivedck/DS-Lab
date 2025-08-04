#include <stdio.h>
#define MAX_TERMS 100

typedef struct {
    int coeff;
    int exp;
} Term;
Term terms[MAX_TERMS];
int avail = 0;
// Function to attach a term to the terms array
void attach(int coeff, int exp) {
    if (avail >= MAX_TERMS) {
        printf("Too many terms\n");
        return;
    }
    terms[avail].coeff = coeff;
    terms[avail].exp = exp;
    avail++;
}
// Function to add two polynomials
void polyAdd(int af, int al, int bf, int bl, int *rf, int *rl) {
    *rf = avail;
    while (af <= al && bf <= bl) {
        if (terms[af].exp < terms[bf].exp) {
            attach(terms[bf].coeff, terms[bf].exp);
            bf++;
        } else if (terms[af].exp > terms[bf].exp) {
            attach(terms[af].coeff, terms[af].exp);
            af++;
        } else {
            int coeff = terms[af].coeff + terms[bf].coeff;
            if (coeff != 0) attach(coeff, terms[af].exp);
            af++;
            bf++;
        }
    }

    // Attach remaining terms
    while (af <= al) attach(terms[af].coeff, terms[af++].exp);

    while (bf <= bl) attach(terms[bf].coeff, terms[bf++].exp);

    *rl = avail - 1;
}

// Function to display polynomial
void display(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (terms[i].coeff == 0) continue;
        if (i > start && terms[i].coeff > 0) printf(" + ");
        if (terms[i].exp == 0)
            printf("%d", terms[i].coeff);
        else if (terms[i].exp == 1)
            printf("%dx", terms[i].coeff);
        else
            printf("%dx^%d", terms[i].coeff, terms[i].exp);
    }
    printf("\n");
}

int main() {
    int a_start = 0, a_end, b_start, b_end;
    int r_start, r_end;
    int n1, n2;

    // Input first polynomial
    printf("Enter number of terms in 1st polynomial: ");
    scanf("%d", &n1);
    printf("Enter terms (coeff and exp) in descending order of exponents:\n");
    for (int i = 0; i < n1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &terms[avail].coeff, &terms[avail].exp);
        avail++;
    }
    a_end = avail - 1;

    // Input second polynomial
    b_start = avail;
    printf("Enter number of terms in 2nd polynomial: ");
    scanf("%d", &n2);
    printf("Enter terms (coeff and exp) in descending order of exponents:\n");
    for (int i = 0; i < n2; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &terms[avail].coeff, &terms[avail].exp);
        avail++;
    }
    b_end = avail - 1;

    // Add the polynomials
    polyAdd(a_start, a_end, b_start, b_end, &r_start, &r_end);

    // Display results
    printf("Polynomial A: ");
    display(a_start, a_end);

    printf("Polynomial B: ");
    display(b_start, b_end);

    printf("Sum: ");
    display(r_start, r_end);

    return 0;
}
