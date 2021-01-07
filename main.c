#include <stdio.h>

#define N 100

void LoadMatrix(int matrix [N][N], int r, int c);
int SumMatrix(int matrix [N][N], int r, int c);
int SumRowColumn(int matrix [N][N], int r, int c);
int SumDiagonals(int matrix [N][N], int r, int c);
int SumPerimeter(int matrix [N][N], int r, int c);
int SumUpAndDownMainDiagonal(int matrix [N][N], int r, int c);
int SumUpAndDownSideDiagonal(int matrix [N][N], int r, int c);
void PrintSum(int a);

int main() {
    int Matrix[N][N], r, c;

    printf("Enter size of the matrix: ");
    scanf("%d %d", &r, &c);

    LoadMatrix(Matrix, r, c);
    PrintSum(SumMatrix(Matrix, r, c));
    PrintSum(SumRowColumn(Matrix, r, c));
    PrintSum(SumDiagonals(Matrix, r, c));
    PrintSum(SumPerimeter(Matrix, r, c));
    PrintSum(SumUpAndDownMainDiagonal(Matrix, r, c));
    PrintSum(SumUpAndDownSideDiagonal(Matrix, r, c));

    return 0;
}

void LoadMatrix(int matrix [N][N], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int SumMatrix(int matrix [N][N], int r, int c) {
    int sum = 0;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            sum = sum + matrix[i][j];
        }
    }

    printf("The sum of matrix is: ");
    return sum;
}

int SumRowColumn(int matrix [N][N], int r, int c) {
    int sum = 0, x, y;

    printf("Enter, which row and column you would like to sum up: ");

    scanf("%d %d", &x, &y);

    if (x < 1 || x > r || y < 1 || y > c)
        perror("ENTERED ROW OR COLUMN IS NOT IN BORDERS OF MATRIX!");
    else{
        x = x - 1;
        y = y - 1;

        for (int i = 0; i < r; ++i) {
            sum = sum + matrix[i][y];
        }

        for (int j = 0; j < c; ++j) {
            sum = sum + matrix[x][j];
        }
        printf("The sum of %d. row and %d. column is: ", x + 1, y + 1);
    }
    return sum;
}

int SumDiagonals(int matrix [N][N], int r, int c) {
    int sum = 0;

    if (r == c) {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < r; ++j) {
                if (i == j)
                    sum = sum + matrix[i][j];
            }
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < r; j++) {
                if ((i + j) == (r - 1))
                    sum = sum + matrix[i][j];
            }
        }
        printf("The sum of main and side diagonal is: ");
    } else
        printf("This matrix is not a square matrix!");

    return sum;
}

int SumPerimeter(int matrix[N][N], int r, int c) {
    int sum = 0;

    for (int i = 0; i < c; ++i) {
        sum = sum + matrix [0][i];
        sum = sum + matrix [r - 1][i];
    }

    for (int i = 0; i < r; ++i) {
        sum = sum + matrix [i][0];
        sum = sum + matrix [i][c - 1];
    }

    sum = sum - matrix [0][0] - matrix [0][c - 1] - matrix [r - 1][0] - matrix [r - 1][c - 1];

    printf("The sum of perimeter is: ");

    return sum;
}

int SumUpAndDownMainDiagonal(int matrix [N][N], int r, int c) {
    int sum = 0;

    if (r == c) {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
               if (i != j)
                   sum = sum + matrix[i][j];
            }
        }
        printf("The sum of numbers above and under main diagonal is: ");
    } else
        printf("This matrix is not a square matrix!");

    return sum;
}

int SumUpAndDownSideDiagonal(int matrix [N][N], int r, int c) {
    int sum = 0;

    if (r == c) {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if ((i + j) != (r - 1))
                    sum = sum + matrix[i][j];
            }
        }
        printf("The sum of numbers above and under side diagonal is: ");
    } else
        printf("This matrix is not a square matrix!");

    return sum;
}

void PrintSum(int a) {
    printf("%d\n", a);
}