#include <iostream>
#include <array> 
using namespace std;

void RowConstant(int matrix[][3], int row, int constant);
void RowSwap(int matrix[][3], int row1, int row2);
void RowAddition(int matrix[][3], int row1, int row2);
void RowSubtraction(int matrix[][3], int row1, int row2);
void DotProduct(int matrixA[][3], int matrixB[][3]);
void MatrixTransposition(int matrix [3][3]);
void GaussianElimination(int matrix [3][3]);

int main() 
{
    int x = 3;
    cout << "What size matrix do you want?" << endl << "Warning: only 3x3 matrices currently work" << endl;
    int matrixA[3][3];

    for (int m = 0; m < 3; m++)
    {
        for (int n = 0; n < 3; n++)
        {
            cout << "Enter value " << m << "x" << n << ":" << endl;
            cin >> matrixA[m][n];
        }
    }

    int loop = 0;

    do {
        cout << "What do you want to do with your matrix?" << endl << "1. Display Matrix" << endl << "2. Gaussian elimination" << endl << "3. Transpose" << endl << "4. Multiply by another matrix" << endl << "5. Find inverted matrix" << endl << "6. Find eigenvalues" << endl << "7. Find eigenvectors" << endl << "8. Diagonalize" << "9. End" << endl;
        int choice;
        cin >> choice;
        loop = choice;

        switch (choice)
        {
            case 1:

            for (int m = 0; m < x; m++)
            {
                for (int n = 0; n < x; n++) 
                {
                    cout << matrixA[m][n] << " ";
                    if (n == x - 1)
                    {
                        cout << endl;
                    }
                }
            }

            break;

            case 2:
            break;

            case 3:
            MatrixTransposition(matrixA);
            break;

            case 4:
            break;

            case 5:
            break;

            case 6:
            break;
            
            case 7:
            break;

            case 8:
            break;

            case 9:
            cout << "Goodbye" << endl;
            return 0;
            break;
        }
    } while (loop > 0 && loop < 10);

}

void RowConstant(int matrix[3][3], int row, int constant) 
{
    for (int n = 0; n < 3; n++)
    {
        matrix[row][n] = matrix[row][n] * constant;
    }
}

void RowSwap(int matrix[3][3], int row1, int row2)
{
    for (int n = 0; n < 3; n++) 
    {
        matrix[row1][n] = matrix[row2][n];
    }
}

void RowAddition(int matrix[3][3], int row1, int row2) 
{
    for (int n = 0; n < 3; n++)
    {
        matrix[row1][n] = matrix[row1][n] + matrix[row2][n];
    }
}

void RowSubtraction(int matrix[3][3], int row1, int row2) 
{
    for (int n = 0; n < 3; n++)
    {
        matrix[row1][n] = matrix[row1][n] - matrix[row2][n];
    }
}

void MatrixTranposition(int matrix[3][3])
{
    for (int m = 0; m < 3; m++)
    {
        for (int n = 0; n < 3; n++)
        {
            matrix[m][n] = matrix[n][m];
        }
    }
}

void GaussianElimination(int matrix[3][3]) 
{
    for (int m = 0; m < 3; m++)
    {
        if (matrix[m][0] == 1 && matrix[m][1] == 0 && matrix[m][2])
        {
            RowSwap(matrix, 0, m);
        }

        if (matrix[m][1] == 1 && matrix[m][0] == 0 && matrix[m][2])
        {
            RowSwap(matrix, 1, m);
        }

        if (matrix[m][2] == 1 && matrix[m][0] == 0 && matrix[m][1])
        {
            RowSwap(matrix, 2, m);
        }
    }


}

void DotProduct(int matrixA[3][3], int matrixB[3][3])
{

}