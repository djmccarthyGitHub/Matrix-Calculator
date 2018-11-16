#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

using namespace std;

class Matrix {

public:
	Matrix();
	Matrix(int row_size, int column_size, string values);
	Matrix(int row_size, int column_size, vector<vector<int>> matrix);
	int getRowSize();
	int getColumnSize();
	vector<vector<int>> getVectors();
	void createMatrix(string values);
	void printMatrix();
private:
	int rows;
	int columns;
	vector<vector<int>> matrix;
};

#endif
