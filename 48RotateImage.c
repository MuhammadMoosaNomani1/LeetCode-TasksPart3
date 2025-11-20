#include <stdio.h>
#include <stdlib.h>

void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    int n = matrixSize;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int left = 0, right = n - 1;
        while (left < right)
        {
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left++;
            right--;
        }
    }
}
int main()
{
    int n;
    printf("Enter size of NxN matrix: ");
    scanf("%d", &n);

    int **matrix = (int **)malloc(n * sizeof(int *));
    int *matrixColSize = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
        matrixColSize[i] = n;
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    rotate(matrix, n, matrixColSize);

    printf("\nMatrix after 90-degree rotation:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }

    free(matrix);
    free(matrixColSize);

    return 0;
}