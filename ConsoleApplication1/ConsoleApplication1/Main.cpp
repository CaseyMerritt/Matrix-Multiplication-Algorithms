// Author: Casey Merritt
// Assignment: Project 1
// Start Date: November 2, 2022

#include "Matrix.h"
#include "Multiplication.h"

#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    cout << "--== Matrix Multiplier ==--" << endl;
    cout << endl;

    int rows = 0;
    int columns = 0;

    cout << "Matrix 1: " << endl;
    cout << "Enter Row Size: ";
    cin >> rows;
    cout << "Enter Column Size: ";
    cin >> columns;
    cout << "-------------------------" << endl;

    Matrix x(rows, columns);
    x.randomPopulate();

    cout << "Matrix 2: " << endl;
    cout << "Enter Row Size: ";
    cin >> rows;
    cout << "Enter Column Size: ";
    cin >> columns;
    cout << "-------------------------" << endl;
    cout << endl;

    Matrix y(rows, columns);
    y.randomPopulate();

    Matrix result;
    cout << endl;
    cout << "Classic: " << endl;
    auto begin = std::chrono::high_resolution_clock::now();
    for (int k = 0; k < 1000; k++) {
        x.randomPopulate();
        y.randomPopulate();

        for (int i = 0; i < 20; i++) {
            result = classic(x, y);
            //result = divideAndConquer(x, y);
            //result = strassen(x, y);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Average time measured: %.3f seconds.\n", (elapsed.count() * 1e-9) / 20000);

    char c;
    cout << endl;
    cout << "Enter Anything To Close... ";
    cin >> c;
}
