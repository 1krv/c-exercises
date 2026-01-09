#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLS 3
#define ROWS 3
#define MATRIX_SIZE (COLS * ROWS * sizeof(int))

/* Prints the given matrix of size cols*rows. */
void print_matrix(int *matrix, int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        printf("[");
        for (int j = 0; j < cols; j++) {
            int val = matrix[i * cols + j];
            printf("%d", val);
        }
        printf("]\n");
    }
}

/* Populates given matrix from user input. */
void populate_matrix(int *matrix, int cols, int rows) {
    printf("\e[1;1H\e[2J");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            print_matrix(matrix, COLS, ROWS);
            printf("insert value of [i][j]:");
            scanf("%d", &matrix[i * cols + j]);
            printf("\e[1;1H\e[2J");
        }
    }
}

int main(void) {
    // Dinamically allocate a matrix
    int *matrix = malloc(MATRIX_SIZE);
    // Set all its value to 0
    memset(matrix, 0, (int)MATRIX_SIZE);

    int d1 = 0;
    int d2 = 0;

    populate_matrix(matrix, COLS, ROWS);
    print_matrix(matrix, COLS, ROWS);

    free(matrix);
    matrix = NULL;
    return 0;
}
