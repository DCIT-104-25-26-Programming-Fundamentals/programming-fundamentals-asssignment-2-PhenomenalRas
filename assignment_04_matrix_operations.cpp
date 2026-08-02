// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool isValidSize(int rows, int columns) {
    return rows > 0 && rows <= 10 && columns > 0 && columns <= 10;
}

// -----------------------------------------------------------------------------
// Function to display a matrix in a formatted grid
// -----------------------------------------------------------------------------
void displayMatrix(int matrix[10][10], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
void transposeMatrix(int matrix[10][10], int rows, int columns) {
    int transpose[10][10];

    // Compute transpose (swap rows and columns)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix, rows, columns);

    cout << "\nTransposed Matrix:\n";
    displayMatrix(transpose, columns, rows);
}

// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
void addMatrices(int matrixA[10][10], int matrixB[10][10],
                 int rows, int columns) {
    int sum[10][10];

    // Compute element-wise sum
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    cout << "\nMatrix A:\n";
    displayMatrix(matrixA, rows, columns);

    cout << "\nMatrix B:\n";
    displayMatrix(matrixB, rows, columns);

    cout << "\nSum of Matrix A and Matrix B:\n";
    displayMatrix(sum, rows, columns);
}

// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
void multiplyMatrices(int matrixA[10][10], int matrixB[10][10],
                      int rowsA, int columnsA,
                      int rowsB, int columnsB) {
    // Initialize product matrix with zeros
    int product[10][10] = {};

    // Compute matrix multiplication: A (rowsA x columnsA) * B (rowsB x columnsB)
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            for (int k = 0; k < columnsA; k++) {
                product[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "\nMatrix A:\n";
    displayMatrix(matrixA, rowsA, columnsA);

    cout << "\nMatrix B:\n";
    displayMatrix(matrixB, rowsB, columnsB);

    cout << "\nProduct of Matrix A and Matrix B:\n";
    displayMatrix(product, rowsA, columnsB);
}

// -----------------------------------------------------------------------------
// MAIN FUNCTION
// -----------------------------------------------------------------------------
int main() {

    // =========================================================================
    // PART A — Transpose a Matrix
    // =========================================================================

    int matrix[10][10];
    int rows, columns;

    cout << "========================================\n";
    cout << "PART A - TRANSPOSE A MATRIX\n";
    cout << "========================================\n";
    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    if (!isValidSize(rows, columns)) {
        cout << "Error: matrix dimensions must be between 1 and 10.\n";
        return 1;
    }

    cout << "\nEnter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    transposeMatrix(matrix, rows, columns);


    // =========================================================================
    // PART B — Add Two Matrices
    // =========================================================================

    int matrixA[10][10];
    int matrixB[10][10];
    int addRows, addColumns;

    cout << "\n\n========================================\n";
    cout << "PART B - ADD TWO MATRICES\n";
    cout << "========================================\n";

    cout << "Enter number of rows: ";
    cin >> addRows;

    cout << "Enter number of columns: ";
    cin >> addColumns;

    if (!isValidSize(addRows, addColumns)) {
        cout << "Error: matrix dimensions must be between 1 and 10.\n";
        return 1;
    }

    cout << "\nEnter elements of Matrix A:\n";
    for (int i = 0; i < addRows; i++) {
        for (int j = 0; j < addColumns; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixA[i][j];
        }
    }

    cout << "\nEnter elements of Matrix B:\n";
    for (int i = 0; i < addRows; i++) {
        for (int j = 0; j < addColumns; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixB[i][j];
        }
    }

    addMatrices(matrixA, matrixB, addRows, addColumns);


    // =========================================================================
    // PART C — Multiply Two Matrices
    // =========================================================================

    int multiplyA[10][10];
    int multiplyB[10][10];

    int rowsA, columnsA;
    int rowsB, columnsB;

    cout << "\n\n========================================\n";
    cout << "PART C - MULTIPLY TWO MATRICES\n";
    cout << "========================================\n";

    cout << "Enter number of rows for Matrix A: ";
    cin >> rowsA;

    cout << "Enter number of columns for Matrix A: ";
    cin >> columnsA;

    cout << "\nEnter number of rows for Matrix B: ";
    cin >> rowsB;

    cout << "Enter number of columns for Matrix B: ";
    cin >> columnsB;

    if (!isValidSize(rowsA, columnsA) || !isValidSize(rowsB, columnsB)) {
        cout << "Error: matrix dimensions must be between 1 and 10.\n";
        return 1;
    }

    // Check if multiplication condition holds true (Columns A == Rows B)
    if (columnsA != rowsB) {
        cout << "\nMatrix multiplication is not possible.\n";
        cout << "The number of columns in Matrix A must equal ";
        cout << "the number of rows in Matrix B.\n";
        return 0;
    }

    cout << "\nEnter elements of Matrix A:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsA; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> multiplyA[i][j];
        }
    }

    cout << "\nEnter elements of Matrix B:\n";
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < columnsB; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> multiplyB[i][j];
        }
    }

    multiplyMatrices(multiplyA, multiplyB, rowsA, columnsA, rowsB, columnsB);

    return 0;
}
