/**************************
 * Author: Ivanova Ksenia *
 * Variant: 6             *
 * Name: Laba 4           *
 **************************/

#include <iostream>

using namespace std;

int main() {
    const int maxSize = 20;
    const int maxMagnitude = 1000;
    int matrix[maxSize][maxSize];
    int matrixSize;

    cout << "Enter matrix size: ";
    if (!(cin >> matrixSize) || matrixSize < 1 || matrixSize > maxSize) {
        cout << "INVALID\n";
        return 1;
    }

    cout << "Enter matrix elements:\n";
    for (int rowIndex = 0; rowIndex < matrixSize; ++rowIndex) {
        for (int columnIndex = 0; columnIndex < matrixSize; ++columnIndex) {
            if (!(cin >> matrix[rowIndex][columnIndex]) ||
                matrix[rowIndex][columnIndex] < -maxMagnitude ||
                matrix[rowIndex][columnIndex] > maxMagnitude) {
                cout << "INVALID\n";
                return 1;
            }
        }
    }

    cout << "\nOriginal matrix:\n";
    for (int rowIndex = 0; rowIndex < matrixSize; ++rowIndex) {
        for (int columnIndex = 0; columnIndex < matrixSize; ++columnIndex) {
            cout << matrix[rowIndex][columnIndex] << " ";
        }
        cout << "\n";
    }

    for (int rowIndex = 0; rowIndex < matrixSize; ++rowIndex) {
        // максимальный элемент в столбце
        int maxElement = matrix[rowIndex][0];
        int maxColumnIndex = 0;

        for (int columnIndex = 1; columnIndex < matrixSize; ++columnIndex) {
            if (matrix[rowIndex][columnIndex] > maxElement) {
                maxElement = matrix[rowIndex][columnIndex];
                maxColumnIndex = columnIndex;
            }
        }

        int tempValue = matrix[rowIndex][rowIndex];
        matrix[rowIndex][rowIndex] = matrix[rowIndex][maxColumnIndex];
        matrix[rowIndex][maxColumnIndex] = tempValue;
    }

    cout << "\nModified matrix:\n";
    for (int rowIndex = 0; rowIndex < matrixSize; ++rowIndex) {
        for (int columnIndex = 0; columnIndex < matrixSize; ++columnIndex) {
            cout << matrix[rowIndex][columnIndex] << " ";
        }
        cout << "\n";
    }

    return 0;
}