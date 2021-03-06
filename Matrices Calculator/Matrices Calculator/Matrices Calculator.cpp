#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// function declarations
Matrix addMatrix(Matrix m1, Matrix m2);
Matrix subtractMatrix(Matrix m1, Matrix m2);
Matrix multiplyMatrix(Matrix m1, Matrix m2);
bool checkValidity(Matrix m1, Matrix m2);
bool isNumber(string input);
bool countValues(string values, int rows, int columns);
void printMenu();

int main()
{
	Matrix m[100];
	int mSize = 0;
	string input;
	while (true) {
		printMenu();
		getline(cin, input);
		cout << endl;
		// check if valid input
		if (isNumber(input)) {
			string rows = "";
			string columns = "";
			string values = "";
			string in = "";
			Matrix m1;
			Matrix m2;
			Matrix m3;
			/*
			switch statement on possible the inputs
			0: create matrix        1: add matrices
			2: subtract matrices    3: multiply matrices
			4: view matrices        5: quit
			*/
			switch (stoi(input)) {
			case(0):
				cout << "Please input the amount of rows for this matrix (i.e. '2' = {}{}" << endl << endl;
				getline(cin, rows);
				// check if valid input
				if (!isNumber(rows)) {
					cout << endl << "Error in input, Matrix not saved" << endl;
					break;
				}
				cout << endl << "Please input the amount of columns for this matrix (i.e. '3' = {1,2,3}" << endl << endl;
				getline(cin, columns);
				// check if valid input
				if (!isNumber(columns)) {
					cout << endl << "Error in input, Matrix not saved" << endl;
					break;
				}
				cout << endl << "Please input the values for this matrix seperated by commas (i.e. '1, 2, 3, 4, 5, 6' = {1,2,3}{4,5,6})" << endl << endl;
				getline(cin, values);
				// check if valid input
				if (!countValues(values, stoi(rows), stoi(columns))) {
					cout << endl << "Error in input, Matrix not saved" << endl;
					break;
				}
				m[mSize] = Matrix(stoi(rows), stoi(columns), values);
				mSize++;
				cout << endl << "This matrix will be saved under Matrix " << mSize;
				break;
			case(1):
				if (mSize >= 2) {
					cout << "Select the first Matrix -   ";
					// print all matrices
					for (int i = 1; i <= mSize; i++) {
						cout << i << ": Matrix " << i << "   ";
					}
					cout << endl << endl;
					getline(cin, in);
					// check if valid input
					if (!isNumber(in) || !stoi(in) < 0 || !stoi(in) > mSize) {
						cout << endl << "Error in input, additon not completed" << endl;
						break;
					}
					m1 = m[stoi(in) - 1];
					cout << endl << "Select the second Matrix -   ";
					// print all matrices
					for (int i = 1; i <= mSize; i++) {
						cout << i << ": Matrix " << i << "   ";
					}
					cout << endl << endl;
					getline(cin, in);
					// check if valid input
					if (!isNumber(in) || !stoi(in) < 0 || !stoi(in) > mSize - 1) {
						cout << endl << "Error in input, additon not completed" << endl;
						break;
					}
					m2 = m[stoi(in) - 1];
					cout << endl;
					m3 = addMatrix(m1, m2);
					cout << endl << "Press '0' to save this Matrix, press anything else to continue" << endl;
					getline(cin, in);
					// saves matrix
					if (in == "0") {
						m[mSize] = m3;
						mSize++;
						cout << endl << "This matrix will be saved as Matrix " << mSize << endl << endl;
					}
				}
				else {
					cout << "Not enough matrices";
				}
				break;
			case(2):
				if (mSize >= 2) {
					cout << "Select the first Matrix -   ";
					// print all matrices
					for (int i = 1; i <= mSize; i++) {
						cout << i << ": Matrix " << i << "   ";
					}
					cout << endl << endl;
					getline(cin, in);
					// check if valid input
					if (!isNumber(in) || !stoi(in) < 0 || !stoi(in) > mSize) {
						cout << endl << "Error in input, subtraction not completed" << endl;
						break;
					}
					m1 = m[stoi(in) - 1];
					cout << endl << "Select the second Matrix -   ";
					// print all matrices
					for (int i = 1; i <= mSize; i++) {
						cout << i << ": Matrix " << i << "   ";
					}
					cout << endl << endl;
					getline(cin, in);
					// check if valid input
					if (!isNumber(in) || !stoi(in) < 0 || !stoi(in) > mSize - 1) {
						cout << endl << "Error in input, subtraction not completed" << endl;
						break;
					}
					m2 = m[stoi(in) - 1];
					cout << endl;
					m3 = subtractMatrix(m1, m2);
					cout << endl << "Press '0' to save this Matrix, press anything else to continue" << endl;
					getline(cin, in);
					// saves matrix
					if (in == "0") {
						m[mSize] = m3;
						mSize++;
						cout << endl << "This matrix will be saved as Matrix " << mSize << endl << endl;
					}
				}
				else {
					cout << "Not enough matrices";
				}
				break;
			case(3):
				if (mSize >= 2) {
					cout << "Select the first Matrix -   ";
					// prints all matrices
					for (int i = 1; i <= mSize; i++) {
						cout << i << ": Matrix " << i << "   ";
					}
					cout << endl << endl;
					getline(cin, in);
					// check if valid input
					if (!isNumber(in) || !stoi(in) < 0 || !stoi(in) > mSize) {
						cout << endl << "Error in input, multiplication not completed" << endl;
						break;
					}
					m1 = m[stoi(in) - 1];
					cout << endl << "Select the second Matrix -   ";
					// prints all matrices
					for (int i = 1; i <= mSize; i++) {
						cout << i << ": Matrix " << i << "   ";
					}
					cout << endl << endl;
					getline(cin, in);
					// check if valid input
					if (!isNumber(in) || !stoi(in) < 0 || !stoi(in) > mSize - 1) {
						cout << endl << "Error in input, multiplication not completed" << endl;
						break;
					}
					m2 = m[stoi(in) - 1];
					cout << endl;
					if (m1.getColumnSize() == m2.getRowSize()) {
						m3 = multiplyMatrix(m1, m2);
						cout << endl << "Press '0' to save this Matrix, press anything else to continue" << endl;
						getline(cin, in);
						// saves matrix
						if (in == "0") {
							m[mSize] = m3;
							mSize++;
							cout << endl << "This matrix will be saved as Matrix " << mSize << endl << endl;
						}
					}
					else {
						cout << "Mismatched matrices, multiplication not completed" << endl;
					}
				}
				else {
					cout << "Not enough matrices";
				}
				break;
			case(4):
				if (mSize > 0) {
					// prints all matrices
					for (int i = 0; i < mSize; i++) {
						cout << "Matrix " << i + 1 << endl;
						m[i].printMatrix();
						cout << endl;
					}
				}
				else {
					cout << "Not enough matrices";
				}
				break;
			case(5):
				// exits application
				return 0;
			default:
				cout << "Error in input please try again";
			}
			cout << endl << endl;
		}
		else {
			cout << "Error in input please try again" << endl << endl;
		}
	}
}


/*
This function takes in two matrices and adds them together
*/
Matrix addMatrix(Matrix m1, Matrix m2) {
	if (checkValidity(m1, m2)) {
		vector<vector<int>> v1 = m1.getVectors();
		vector<vector<int>> v2 = m2.getVectors();
		vector<vector<int>> v3;
		v3.resize(m1.getRowSize());
		for (int i = 0; i < m1.getRowSize(); ++i)
			v3[i].resize(m2.getColumnSize());

		for (int i = 0; i < m1.getRowSize(); i++) {
			for (int j = 0; j < m2.getColumnSize(); j++) {
				v3[i][j] = v1[i][j] + v2[i][j];
			}
		}
		Matrix m(m1.getColumnSize(), m1.getRowSize(), v3);
		m.printMatrix();
		return m;
	}
	else {
		cout << "Matrix bounds did not match, unable to add matrices" << endl;
	}
}

/*
This function takes in two matrices and subtracts them
The second Matrix inputed to the function will be subtracted from the first
*/
Matrix subtractMatrix(Matrix m1, Matrix m2) {
	if (checkValidity(m1, m2)) {
		vector<vector<int>> v1 = m1.getVectors();
		vector<vector<int>> v2 = m2.getVectors();
		vector<vector<int>> v3;
		v3.resize(m1.getRowSize());
		for (int i = 0; i < m1.getRowSize(); ++i)
			v3[i].resize(m1.getColumnSize());

		for (int i = 0; i < m1.getRowSize(); i++) {
			for (int j = 0; j < m1.getColumnSize(); j++) {
				v3[i][j] = v1[i][j] - v2[i][j];
			}
		}
		Matrix m(m1.getRowSize(), m1.getColumnSize(), v3);
		m.printMatrix();
		return m;
	}
	else {
		cout << "Matrix bounds did not match, unable to subtract matrices" << endl;
	}
}

/*
This function takes in two matrices and multiplies them together
*/
Matrix multiplyMatrix(Matrix m1, Matrix m2) {
	vector<vector<int>> v1 = m1.getVectors();
	vector<vector<int>> v2 = m2.getVectors();
	vector<vector<int>> v3;
	v3.resize(m1.getRowSize());
	for (int i = 0; i < m1.getRowSize(); ++i)
		v3[i].resize(m2.getColumnSize());

	int x = 0;
	for (int i = 0; i < (m1.getRowSize()); i++) {
		int y = 0;
		for (int j = 0; j < m2.getColumnSize(); j++) {
			int sum = 0;
			for (int k = 0; k < m2.getRowSize(); k++) {
				sum += v1[i][k] * v2[k][j];
			}
			v3[x][y] = sum;
			y++;
		}
		x++;
	}
	Matrix m(m1.getRowSize(), m2.getColumnSize(), v3);
	m.printMatrix();
	return m;
}

/*
This function checks if the two matrices can be added or subtracted
*/
bool checkValidity(Matrix m1, Matrix m2) {
	if (m1.getRowSize() == m2.getRowSize() && m1.getColumnSize() == m2.getColumnSize()) {
		return true;
	}
	else {
		return false;
	}
}

/*
This function checks if a string input is a number
*/
bool isNumber(string input) {
	string::const_iterator it = input.begin();
	while (it != input.end() && isdigit(*it)) ++it;
	return !input.empty() && it == input.end();
}

/*
This function checks if the input for a matrix is valid
It checks that every input in a number, comma, or space
It also makes sure there is a valid amount of numbers in the string
*/
bool countValues(string values, int rows, int columns) {
	int n = count(values.begin(), values.end(), ',');
	if (n == (rows * columns) - 1) {
		string::const_iterator it = values.begin();
		while (it != values.end() && (isdigit(*it) || *it == ',' || *it == ' ')) ++it;
		return !values.empty() && it == values.end();
		return true;
	}
	else {
		return false;
	}
}

/*
This function prints the menu to the console
*/
void printMenu() {
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "0: Create a matrix   1: Add matrices   2: Subtract matrices   3: Multiply matrices   4: View matrices   5: Quit  |" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Please press the key corresponding to what you would like to do" << endl << endl;
}