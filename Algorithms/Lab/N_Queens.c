#include <stdio.h>
#include <stdbool.h>
#define N_MAX 10
int N;
void printSolution(int board[N_MAX][N_MAX]);
bool isSafe(int board[N_MAX][N_MAX], int row, int col);
bool solveNQueen(int board[N_MAX][N_MAX], int col);
int main()
{
    printf("Enter size of board: ");
    scanf("%d", &N);
    int board[N_MAX][N_MAX];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
    if (!solveNQueen(board, 0))
    {
        printf("Solution does not exist\n");
        return 0;
    }
    printSolution(board);
    return 0;
}
void printSolution(int board[N_MAX][N_MAX])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}
bool isSafe(int board[N_MAX][N_MAX], int row, int col)
{
    int i, j;
    // Check for Same Row
    for (i = col - 1; i >= 0; i--)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }
    // Check for Upper Diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    // Check for Lower Diagonal
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
bool solveNQueen(int board[N_MAX][N_MAX], int col)
{
    if (col >= N)
    {
        return true;
    }
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            if (solveNQueen(board, col + 1))
            {
                return true;
            }
            // Backtrack if the above condition is false
            board[i][col] = 0;
        }
    }
    return false;
}