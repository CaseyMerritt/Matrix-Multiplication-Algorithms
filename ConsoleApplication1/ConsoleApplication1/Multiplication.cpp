// Author: Casey Merritt
// Assignment: Project 1
// Start Date: November 2, 2022

#include "Multiplication.h"

//Classic Matrix Multiplication
//O(n^3) time complexity
Matrix classic(Matrix x, Matrix y) {
	int n1 = x.getRows();
	int n2 = y.getCols();
	Matrix result(x.getRows(), y.getCols());

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			for (int k = 0; k < n1; k++) {
				result.arr[i][j] += x.arr[i][k] * y.arr[k][j];
			}
		}
	}
	
	return result;
}

//Divide And Conquer Matrix Multiplication
//O(n^3) time complexity
Matrix divideAndConquer(Matrix A, Matrix B) {
	Matrix result(A.getRows(), B.getCols());

	int n = A.getRows();

	if (n <= 2) {
		return classic(A, B);
	}

	Matrix a(n / 2, n / 2), b(n / 2, n / 2), c(n / 2, n / 2), d(n / 2, n / 2);
	Matrix e(n / 2, n / 2), f(n / 2, n / 2), g(n / 2, n / 2), h(n / 2, n / 2);

	for (auto i = 0; i < (n / 2); i++) {
		for (auto j = 0; j < (n / 2); j++) {
			a.arr[i][j] = A.arr[i][j];
			b.arr[i][j] = A.arr[i][j + (n / 2)];
			c.arr[i][j] = A.arr[(n / 2) + i][j];
			d.arr[i][j] = A.arr[i + (n / 2)][j + (n / 2)];

			e.arr[i][j] = B.arr[i][j];
			f.arr[i][j] = B.arr[i][j + (n / 2)];
			g.arr[i][j] = B.arr[(n / 2) + i][j];
			h.arr[i][j] = B.arr[i + (n / 2)][j + (n / 2)];
		}
	}

	Matrix ae = divideAndConquer(a, e);
	Matrix bg = divideAndConquer(b, g);
	Matrix af = divideAndConquer(a, f);
	Matrix bh = divideAndConquer(b, h);

	Matrix ce = divideAndConquer(c, e);
	Matrix dg = divideAndConquer(d, g);
	Matrix cf = divideAndConquer(c, f);
	Matrix dh = divideAndConquer(d, h);

	Matrix c11 = addMatrix(ae, bg, (n / 2));
	Matrix c12 = addMatrix(af, bh, (n / 2));
	Matrix c21 = addMatrix(ce, dg, (n / 2));
	Matrix c22 = addMatrix(cf, dh, (n / 2));

	for (auto i = 0; i < (n / 2); i++) {
		for (auto j = 0; j < (n / 2); j++) {
			result.arr[i][j] = c11.arr[i][j];
			result.arr[i][j + (n / 2)] = c12.arr[i][j];
			result.arr[(n / 2) + i][j] = c21.arr[i][j];
			result.arr[i + (n / 2)][j + (n / 2)] = c22.arr[i][j];
		}
	}

	return result;
}

//Strassen Matrix Multiplication
//O(n^2.81) Time Complexity
Matrix strassen(Matrix A, Matrix B) {
	Matrix result(A.getRows(), B.getCols());

	int n = A.getRows();

	if (A.getRows() <= 2) {
		return classic(A, B);
	}

	Matrix a(n / 2, n / 2), b(n / 2, n / 2), c(n / 2, n / 2), d(n / 2, n / 2);
	Matrix e(n / 2, n / 2), f(n / 2, n / 2), g(n / 2, n / 2), h(n / 2, n / 2);

	for (auto i = 0; i < (n / 2); i++) {
		for (auto j = 0; j < (n / 2); j++) {
			a.arr[i][j] = A.arr[i][j];
			b.arr[i][j] = A.arr[i][j + (n / 2)];
			c.arr[i][j] = A.arr[(n / 2) + i][j];
			d.arr[i][j] = A.arr[i + (n / 2)][j + (n / 2)];

			e.arr[i][j] = B.arr[i][j];
			f.arr[i][j] = B.arr[i][j + (n / 2)];
			g.arr[i][j] = B.arr[(n / 2) + i][j];
			h.arr[i][j] = B.arr[i + (n / 2)][j + (n / 2)];
		}
	}

	Matrix p1 = strassen(addMatrix(a, d, (n / 2)), addMatrix(e, h, (n / 2)));
	Matrix p2 = strassen(d, subMatrix(g, e, (n / 2)));
	Matrix p3 = strassen(addMatrix(a, b, (n / 2)), h);
	Matrix p4 = strassen(subMatrix(b, d, (n / 2)), addMatrix(g, h, (n / 2)));
	Matrix p5 = strassen(a, subMatrix(f, h, (n / 2)));
	Matrix p6 = strassen(addMatrix(c, d, (n / 2)), e);
	Matrix p7 = strassen(subMatrix(a, c, (n / 2)), addMatrix(e, f, (n / 2)));

	Matrix c11 = addMatrix(p1, p2, (n / 2));
	c11 = subMatrix(c11, p3, (n / 2));
	c11 = addMatrix(c11, p4, (n / 2));

	Matrix c12 = addMatrix(p5, p3, (n / 2));
	Matrix c21 = addMatrix(p6, p2, (n / 2));

	Matrix c22 = addMatrix(p5, p1, (n / 2));
	c22 = subMatrix(c22, p6, (n / 2));
	c22 = subMatrix(c22, p7, (n / 2));

	for (auto i = 0; i < (n / 2); i++){
		for (auto j = 0; j < (n / 2); j++) {
			result.arr[i][j] = c11.arr[i][j];
			result.arr[i][j + (n / 2)] = c12.arr[i][j];
			result.arr[(n / 2) + i][j] = c21.arr[i][j];
			result.arr[i + (n / 2)][j + (n / 2)] = c22.arr[i][j];
		}
	}

	return result;
}

//adds twp matrices together
Matrix addMatrix(Matrix a, Matrix b, int index) {
	Matrix result(a.getRows(), a.getCols());

	for (auto i = 0; i < index; i++) {
		for (auto j = 0; j < index; j++) {
			result.arr[i][j] = (a.arr[i][j] + b.arr[i][j]);
		}
	}

	return result;
}

//subtracts two matrices 
Matrix subMatrix(Matrix a, Matrix b, int index) {
	Matrix result(a.getRows(), a.getCols());

	for (auto i = 0; i < index; i++) {
		for (auto j = 0; j < index; j++) {
			result.arr[i][j] = (a.arr[i][j] - b.arr[i][j]);
		}
	}

	return result;
}