#include <stdio.h>
#include <stdlib.h>
#define ROW_1 3
#define COL_1 2
#define ROW_2 2
#define COL_2 4
void printMat(int **a, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void print(char *display, int **matrix, int start_row, int start_column, int end_row, int end_column)
{
    printf("%s =>\n", display);
    for (int i = start_row; i <= end_row; i++)
    {
        for (int j = start_column; j <= end_column; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void add_matrix(int **matrix_A, int **matrix_B, int **matrix_C, int split_index)
{
    for (int i = 0; i < split_index; i++)
    {
        for (int j = 0; j < split_index; j++)
        {
            matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }
    }
}
void initWithZeros(int **a, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            a[i][j] = 0;
        }
    }
}
int **multiply_matrix(int **matrix_A, int **matrix_B, int row_1, int col_1, int col_2)
{
    int row_2 = col_1; // row_2 equals col_1 in Java implementation
    int **result_matrix = (int **)malloc(row_1 * sizeof(int *));
    for (int i = 0; i < row_1; i++)
    {
        result_matrix[i] = (int *)malloc(col_2 * sizeof(int));
    }
    initWithZeros(result_matrix, row_1, col_2);
    if (col_1 == 1)
    {
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    }
    else
    {
        int split_index = col_1 / 2;
        int **result_matrix_00 = (int **)malloc(split_index * sizeof(int *));
        int **result_matrix_01 = (int **)malloc(split_index * sizeof(int *));
        int **result_matrix_10 = (int **)malloc(split_index * sizeof(int *));
        int **result_matrix_11 = (int **)malloc(split_index * sizeof(int *));
        for (int i = 0; i < split_index; i++)
        {
            result_matrix_00[i] = (int *)malloc(split_index * sizeof(int));
            result_matrix_01[i] = (int *)malloc(split_index * sizeof(int));
            result_matrix_10[i] = (int *)malloc(split_index * sizeof(int));
            result_matrix_11[i] = (int *)malloc(split_index * sizeof(int));
        }
        initWithZeros(result_matrix_00, split_index, split_index);
        initWithZeros(result_matrix_01, split_index, split_index);
        initWithZeros(result_matrix_10, split_index, split_index);
        initWithZeros(result_matrix_11, split_index, split_index);
        int **a00 = (int **)malloc(split_index * sizeof(int *));
        int **a01 = (int **)malloc(split_index * sizeof(int *));
        int **a10 = (int **)malloc(split_index * sizeof(int *));
        int **a11 = (int **)malloc(split_index * sizeof(int *));
        int **b00 = (int **)malloc(split_index * sizeof(int *));
        int **b01 = (int **)malloc(split_index * sizeof(int *));
        int **b10 = (int **)malloc(split_index * sizeof(int *));
        int **b11 = (int **)malloc(split_index * sizeof(int *));
        for (int i = 0; i < split_index; i++)
        {
            a00[i] = (int *)malloc(split_index * sizeof(int));
            a01[i] = (int *)malloc(split_index * sizeof(int));
            a10[i] = (int *)malloc(split_index * sizeof(int));
            a11[i] = (int *)malloc(split_index * sizeof(int));
            b00[i] = (int *)malloc(split_index * sizeof(int));
            b01[i] = (int *)malloc(split_index * sizeof(int));
            b10[i] = (int *)malloc(split_index * sizeof(int));
            b11[i] = (int *)malloc(split_index * sizeof(int));
        }
        initWithZeros(a00, split_index, split_index);
        initWithZeros(a01, split_index, split_index);
        initWithZeros(a10, split_index, split_index);
        initWithZeros(a11, split_index, split_index);
        initWithZeros(b00, split_index, split_index);
        initWithZeros(b01, split_index, split_index);
        initWithZeros(b10, split_index, split_index);
        initWithZeros(b11, split_index, split_index);
        for (int i = 0; i < split_index; i++)
        {
            for (int j = 0; j < split_index; j++)
            {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + split_index];
                a10[i][j] = matrix_A[split_index + i][j];
                a11[i][j] = matrix_A[i + split_index][j + split_index];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + split_index];
                b10[i][j] = matrix_B[split_index + i][j];
                b11[i][j] = matrix_B[i + split_index][j + split_index];
            }
        }
        int **temp1 = multiply_matrix(a00, b00, split_index, split_index, split_index);
        int **temp2 = multiply_matrix(a01, b10, split_index, split_index, split_index);
        int **temp3 = multiply_matrix(a00, b01, split_index, split_index, split_index);
        int **temp4 = multiply_matrix(a01, b11, split_index, split_index, split_index);
        int **temp5 = multiply_matrix(a10, b00, split_index, split_index, split_index);
        int **temp6 = multiply_matrix(a11, b10, split_index, split_index, split_index);
        int **temp7 = multiply_matrix(a10, b01, split_index, split_index, split_index);
        int **temp8 = multiply_matrix(a11, b11, split_index, split_index, split_index);
        add_matrix(temp1, temp2, result_matrix_00, split_index);
        add_matrix(temp3, temp4, result_matrix_01, split_index);
        add_matrix(temp5, temp6, result_matrix_10, split_index);
        add_matrix(temp7, temp8, result_matrix_11, split_index);
        for (int i = 0; i < split_index; i++)
        {
            for (int j = 0; j < split_index; j++)
            {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + split_index] = result_matrix_01[i][j];
                result_matrix[split_index + i][j] = result_matrix_10[i][j];
                result_matrix[i + split_index][j + split_index] = result_matrix_11[i][j];
            }
        }
        for (int i = 0; i < split_index; i++)
        {
            free(temp1[i]);
            free(temp2[i]);
            free(temp3[i]);
            free(temp4[i]);
            free(temp5[i]);
            free(temp6[i]);
            free(temp7[i]);
            free(temp8[i]);
        }
        free(temp1);
        free(temp2);
        free(temp3);
        free(temp4);
        free(temp5);
        free(temp6);
        free(temp7);
        free(temp8);
    }
    return result_matrix;
}
int main()
{
    int row_1 = 4, col_1 = 4, row_2 = 4, col_2 = 4;
    int **matrix_A = (int **)malloc(row_1 * sizeof(int *));
    for (int i = 0; i < row_1; i++)
    {
        matrix_A[i] = (int *)malloc(col_1 * sizeof(int));
    }
    matrix_A[0][0] = 1;
    matrix_A[0][1] = 1;
    matrix_A[0][2] = 1;
    matrix_A[0][3] = 1;
    matrix_A[1][0] = 2;
    matrix_A[1][1] = 2;
    matrix_A[1][2] = 2;
    matrix_A[1][3] = 2;
    matrix_A[2][0] = 3;
    matrix_A[2][1] = 3;
    matrix_A[2][2] = 3;
    matrix_A[2][3] = 3;
    matrix_A[3][0] = 2;
    matrix_A[3][1] = 2;
    matrix_A[3][2] = 2;
    matrix_A[3][3] = 2;
    printf("Array A =>\n");
    printMat(matrix_A, row_1, col_1);
    int **matrix_B = (int **)malloc(row_2 * sizeof(int *));
    for (int i = 0; i < row_2; i++)
    {
        matrix_B[i] = (int *)malloc(col_2 * sizeof(int));
    }
    matrix_B[0][0] = 1;
    matrix_B[0][1] = 1;
    matrix_B[0][2] = 1;
    matrix_B[0][3] = 1;
    matrix_B[1][0] = 2;
    matrix_B[1][1] = 2;
    matrix_B[1][2] = 2;
    matrix_B[1][3] = 2;
    matrix_B[2][0] = 3;
    matrix_B[2][1] = 3;
    matrix_B[2][2] = 3;
    matrix_B[2][3] = 3;
    matrix_B[3][0] = 2;
    matrix_B[3][1] = 2;
    matrix_B[3][2] = 2;
    matrix_B[3][3] = 2;
    printf("Array B =>\n");
    printMat(matrix_B, row_2, col_2);
    int **result_matrix = multiply_matrix(matrix_A, matrix_B, row_1, col_1, col_2);
    printf("Result Array =>\n");
    printMat(result_matrix, row_1, col_2);
    for (int i = 0; i < row_1; i++)
    {
        free(matrix_A[i]);
    }
    free(matrix_A);
    for (int i = 0; i < row_2; i++)
    {
        free(matrix_B[i]);
    }
    free(matrix_B);
    for (int i = 0; i < row_1; i++)
    {
        free(result_matrix[i]);
    }
    free(result_matrix);
    return 0;
}