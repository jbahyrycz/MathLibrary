#include "header.h"

using namespace std;

int forwardElim(double matrix[N][N + 1]);
void backSub(double matrix[N][N + 1]);
void print(double matrix[N][N + 1]);

void GaussianElimination(double matrix[N][N + 1])
{
    print(matrix);
    int singular_flag = forwardElim(matrix);

    if (singular_flag != -1)
    {
        if (matrix[singular_flag][N])
            printf("Inconsistent System.");
        else
            printf("May have infinitely many solutions.");

        return;
    }
    backSub(matrix);
}

void swap_row(double matrix[N][N + 1], int i, int j)
{
    for (int k = 0; k <= N; k++)
    {
        double temp = matrix[i][k];
        matrix[i][k] = matrix[j][k];
        matrix[j][k] = temp;
    }
}

void print(double matrix[N][N + 1])
{
    for (int i = 0; i < N; i++, printf("\n"))
        for (int j = 0; j <= N; j++)
            printf("%lf ", matrix[i][j]);

    printf("\n");
}

int forwardElim(double matrix[N][N + 1])
{
    for (int k = 0; k < N; k++)
    {
        int i_max = k;
        int v_max = matrix[i_max][k];

        for (int i = k + 1; i < N; i++)
            if (abs(matrix[i][k]) > v_max)
                v_max = matrix[i][k], i_max = i;

        if (!matrix[k][i_max])
            return k;

        if (i_max != k)
            swap_row(matrix, k, i_max);


        for (int i = k + 1; i < N; i++)
        {
            double f = matrix[i][k] / matrix[k][k];

            for (int j = k + 1; j <= N; j++)
                matrix[i][j] -= matrix[k][j] * f;

            matrix[i][k] = 0;
        }
        print(matrix);
    }
    print(matrix);
    return -1;
}

void backSub(double matrix[N][N + 1])
{
    double x[N];

    for (int i = N - 1; i >= 0; i--)
    {
        x[i] = matrix[i][N];

        for (int j = i + 1; j < N; j++)
        {
            x[i] -= matrix[i][j] * x[j];
        }

        x[i] = x[i] / matrix[i][i];
    }

    printf("\nSolution for the system:\n");
    for (int i = 0; i < N; i++)
        printf("%lf\n", x[i]);
}