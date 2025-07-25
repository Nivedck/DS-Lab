#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fs;
    char ch;
    long count = 0;

    if (argc != 2) {
        printf("Invalid number of arguments.\n");
        return 1;
    }

    fs = fopen(argv[1], "r");
    if (fs == NULL) {
        printf("Source file cannot be opened.\n");
        return 1;
    }

    while ((ch = fgetc(fs)) != EOF) {
        count++;
    }

    fclose(fs);

    printf("The number of characters in %s is %ld\n", argv[1], count);
    return 0;
}

