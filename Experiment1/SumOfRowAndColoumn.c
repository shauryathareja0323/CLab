#include <stdio.h>

int main() {
    int rows, cols, i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }


    int row_sums[rows];
    for (i = 0; i < rows; i++) {
        row_sums[i] = 0;
        for (j = 0; j < cols; j++) {
            row_sums[i] += matrix[i][j];
        }
    }

    int col_sums[cols];
    for (j = 0; j < cols; j++) {
        col_sums[j] = 0;
        for (i = 0; i < rows; i++) {
            col_sums[j] += matrix[i][j];
        }
    }

    
    printf("Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        } 
        printf("\n");
    }

    printf("Row Sum: ");
    for (j = 0; j < rows; j++) {
        printf("%d ", row_sums[j]);
    }
    printf("\n");


    printf("Column Sum: ");
    for (j = 0; j < cols; j++) {
        printf("%d ", col_sums[j]);
    }
    printf("\n");

    return 0;
}
