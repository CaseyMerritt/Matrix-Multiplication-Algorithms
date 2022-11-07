#pragma once
// Author: Casey Merritt
// Assignment: Project 1
// Start Date: November 2, 2022

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class Matrix
{
private:
	int rows;
	int cols;

public:
	vector<vector<int>> arr;

	void printMatrix();
	void randomPopulate();
	int getRows();
	int getCols();

	Matrix() {
		rows = 2;
		cols = 2;
		arr = vector<vector<int>>(rows, vector<int>(cols));
	}

	Matrix(int r, int c) {
		rows = r;
		cols = c;
		arr = vector<vector<int>>(rows, vector<int>(cols));
	}

	~Matrix() {
		arr.clear();
	}


};
