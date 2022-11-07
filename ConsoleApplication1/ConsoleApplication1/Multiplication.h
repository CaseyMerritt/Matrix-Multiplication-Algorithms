// Author: Casey Merritt
// Assignment: Project 1
// Start Date: November 2, 2022

#pragma once

#include "Matrix.h"

Matrix classic(Matrix x, Matrix y);
Matrix divideAndConquer(Matrix x, Matrix y);
Matrix strassen(Matrix x, Matrix y);
Matrix addMatrix(Matrix a, Matrix b, int index);
Matrix subMatrix(Matrix a, Matrix b, int index);