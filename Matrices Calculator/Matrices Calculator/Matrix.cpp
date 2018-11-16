#include "Matrix.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

// creates an empty Matrix
Matrix::Matrix() {
	rows = 0;
	columns = 0;
	matrix = {};
}

// creates a Matrix of given values (int, int, string)
Matrix::Matrix(int row_size, int column_size, string values) {
	this->rows = row_size;
	this->columns = column_size;
	createMatrix(values);
}

// creates a Matrix of given values (int, int, vector< vector <int> >)
Matrix::Matrix(int row_size, int column_size, vector<vector<int>> matrix) {
	this->rows = row_size;
	this->columns = column_size;
	this->matrix = matrix;
}

// returns rows
int Matrix::getRowSize() {
	return rows;
}

// returns columns
int Matrix::getColumnSize() {
	return columns;
}

// returns matrix
vector<vector<int>> Matrix::getVectors() {
	return matrix;
}

// creates the matrix for the Matrix class
void Matrix::createMatrix(string values) {
	string parsed;
	int i = 0;
	int	j = 0;
	stringstream input_stringstream(values);

	// sets size of matrix
	matrix.resize(rows);
	for (int i = 0; i < rows; ++i)
		matrix[i].resize(columns);

	// parses string on ','
	while (getline(input_stringstream, parsed, ','))
	{
		// adds previous value to matrix as number
		matrix[i][j] = stoi(parsed);
		j++;
		if (j == columns) {
			j = 0;
			i++;
		}
	}
}

// prints the matrix to the console
void Matrix::printMatrix() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << setw(3) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}