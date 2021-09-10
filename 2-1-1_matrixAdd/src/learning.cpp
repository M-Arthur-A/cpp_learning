////============================================================================
//// Name        : learning.cpp
//// Description : Coursera task: sum of matrix
////============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <iterator>

using namespace std;

class Matrix {
	int row_num;
	int col_num;

	public:
	vector<vector<int>> rows;
	Matrix(int row = 0, int col = 0) {
		Reset(row, col);
	}
	int GetNumRows() const {return row_num;}
	int GetNumCols() const {return col_num;}

	void Reset(int row, int col) {
		if (row < 0 or col < 0) {
			throw out_of_range("o_o_r");
		} else {
			row_num = row;
			col_num = col;
			rows.clear(); // erase(begin(rows), end(rows));
			rows.assign(row_num, vector<int>(col_num));
		}
	}

	int At (const int& row, const int& col) const { // for reading Matrix
		if (row < 0 or row > row_num or col < 0 or col > col_num) {
			throw out_of_range("o_o_r");
		} else {
			return rows.at(row).at(col);//rows[row][col];
		}
	}

	int& At (const int& row, const int& col) { // for filling Matrix
			if (row < 0 or row > row_num or col < 0 or col > col_num) {
				throw out_of_range("o_o_r");
			} else {
				return rows.at(row).at(col);//rows[row][col];
			}
		}

	bool operator!=(const Matrix* rhs) const {
		if ((GetNumRows() != rhs->GetNumRows()) || (GetNumCols() != rhs->GetNumCols()) ) {
			return true;
		} else { return false;}
	}

	Matrix operator+(const Matrix& rhs) const {
		/* checking for equal */
		if (this != &rhs) {
			if (GetNumRows() != rhs.GetNumRows()) {
				throw invalid_argument("Mismatched number of rows");
			}
			if (GetNumCols() != rhs.GetNumCols()) {
				throw invalid_argument("Mismatched number of columns");
			}
		}
		Matrix result(GetNumRows(), GetNumCols());
		cout << "Result Matrix created with size: ( ";
		cout << result.rows.size() << " row('s) and ";
		cout << result.rows.at(0).size() << " col('s) )" << endl;

		for (int i = 0; i < result.GetNumRows(); i++) {
			for (int j = 0; j < result.GetNumCols(); j++){
				result.At(i, j) = At(i, j) + rhs.At(i, j);
			}
		}
		return result;
	}

	void Print() const {
		cout << "NEW Matrix is:" << endl;
		for(unsigned i = 0; i < rows.size(); i++) {
			cout << "[ ";
			for(unsigned j = 0; j < rows.at(i).size(); j++) {
				cout << rows.at(i).at(j) << " ";
			}
			cout << "]" << endl << endl;
		}
	}
};

istream& operator>>(istream& in, Matrix& matrix) {
	int num_rows, num_columns;
	cout << "row_num?:" << endl;
	in >> num_rows;
	cout << "col_num?:" << endl;
	in >> num_columns;
	matrix.Reset(num_rows, num_columns);
	for (int row = 0; row < num_rows; row++) {
		for (int column = 0; column < num_columns; column++) {
			cout << column+1 << " value of " << row+1 << " row:" << endl;
			in >> matrix.At(row, column);
		}
	}
	matrix.Print();
	return in;
}

ostream& operator<<(ostream& out, const Matrix& matrix) {
	for (int row = 0; row < matrix.GetNumRows(); row++) {
		out << "[ ";
		for (int column = 0; column < matrix.GetNumCols(); column++) {
			out << matrix.At(row, column) << " ";
		}
		out << "]" << endl;
	}
	out << endl;
	return out;
}


int main() {
	try {
		Matrix one;
		Matrix two;
		cin >> one >> two;
		cout << one + two << endl;
	} catch (const out_of_range& oor) {
		cout << "Out of Range error: " << oor.what() << endl;
	}
	return 0;
}
