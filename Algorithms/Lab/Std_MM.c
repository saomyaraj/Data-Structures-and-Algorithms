#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void matrixMultiply(int row1, int col1, int row2, int col2)
{
    if (col1 != row2)
    {
        printf("\nArrays can't be multiplied!!");
        return;
    }
    // First Array
    printf("\nEnter elements of 1st array\n");
    int a[row1][col1];
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            a[i][j] = rand() % 20 + 1;
        }
    }
    printf("1st Array:\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    // Second Array
    printf("\nEnter elements of 2nd array\n");
    int b[row2][col2];
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            b[i][j] = rand() % 30 + 21;
        }
    }
    printf("2nd Array:\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    // Multiplying Array
    int c[row1][col2];
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < row2; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("\nThe Multiplied array is:\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    srand(time(NULL));
    int row1, col1, row2, col2;
    printf("Enter no. of rows of 1st array: ");
    scanf("%d", &row1);
    printf("Enter no. of columns of 1st array: ");
    scanf("%d", &col1);
    printf("Enter no. of rows of 2nd array: ");
    scanf("%d", &row2);
    printf("Enter no. of columns of 2nd array: ");
    scanf("%d", &col2);
    matrixMultiply(row1, col1, row2, col2);
    return 0;
}