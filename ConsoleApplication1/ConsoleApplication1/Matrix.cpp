// Author: Casey Merritt
// Assignment: Project 1
// Start Date: November 2, 2022

#include "Matrix.h"

//Prints Matrix
void Matrix::printMatrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(8) << arr[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

//populates the matrix with random values from 1 to 9
void Matrix::randomPopulate() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int x = rand() % 9 + 1;
            arr[i][j] = x;
        }
    }
}

//returns cols
int Matrix::getCols() {
    return cols;
}

//returns rows
int Matrix::getRows() {
    return rows;
}
