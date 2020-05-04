#include "Matrix1.h"
template <typename Type>
Matrix<Type>::Matrix() : rows(0), cols(0), m(0) {}

template <typename Type1>
Matrix<Type1>::Matrix(int rows, int cols) {
	if (rows > 0 && cols > 0) {
		m = new Type1 * [rows];
		for (int i = 0; i < rows; i++) {
			m[i] = new Type1[cols];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				m[i][j] = 0;
			}
		}
		this->rows = rows;
		this->cols = cols;
	}
	else
		cout << "Error!!!" << endl;
}

template <typename Type2>
Matrix<Type2>::Matrix(const Matrix<Type2>& a) {
	Type2** matr = new Type2 * [a.rows];
	for (int i = 0; i < a.rows; i++) {
		matr[i] = new Type2[a.cols];
	}
	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			matr[i][j] = a.m[i][j];
		}
	}
	this->rows = a.rows;
	this->cols = a.cols;
}

template <typename Type1>
void Matrix<Type1>::SetRows(int rows) {
	if (rows > 0) this->rows = rows;
	else cout << "Error!!!" << endl;
}

template <typename Type3>
void Matrix<Type3>::SetCols(int cols) {
	if (cols > 0) this->cols = cols;
	else cout << "Error!!!" << endl;
}

template <typename Type1>
int Matrix<Type1>::GetRows() const {
	return this->rows;
}

template <typename Type3>
int Matrix<Type3>::GetCols() const {
	return this->cols;
}

template <typename Type1>
void Matrix<Type1> ::SetMatrix(int rows, int cols) {
	m = new Type1 * [rows];
	for (int i = 0; i < rows; i++) {
		m[i] = new Type1[cols];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << m[i][j] = rand() % 10 << "\t";
		}
		cout << endl;
	}
}

template <typename Type3>
Type3** Matrix<Type3>::GetMatrix() {
	return m;
}

template <typename Type>
Matrix<Type> Matrix<Type>:: operator+ (const Matrix<Type>& a) {
	if (this->rows = a.rows && this->cols = a.cols) {
		Matrix<Type> NewMatrix(int rows, int cols);
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->cols; j++) {
				NewMatrix[i][j] = this->m[i][j] + a.m[i][j];
			}
		}
		return NewMatrix;
	}
	else cout << "Error operator +" << endl;

}

template <typename Type>
Matrix<Type> Matrix<Type>:: operator- (const Matrix<Type>& a) {
	if (this->rows = a.rows && this->cols = a.cols) {
		Matrix<Type> NewMatrix(int rows, int cols);
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->cols; j++) {
				NewMatrix[i][j] = this->m[i][j] - a.m[i][j];
			}
		}
		return NewMatrix;
	}
	else cout << "Error operator -" << endl;

}

template <typename Type5>
Matrix<Type5> Matrix<Type5>:: operator* (const Matrix<Type5>& a) {
	if (this->rows = a.rows && this->cols = a.cols) {
		Matrix<Type5> NewMatrix(rows, cols);
		Type5 Sum;
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->cols; j++) {
				Sum = 0;
				for (int l = 0; l < this->rows; l++) {
					Sum = Sum + (this->m[i][l]) * (a.m[l][j]);
				}
				NewMatrix[i][j] = Sum;
			}
		}
		return NewMatrix;
	}
	else cout << "Error operator *" << endl;
}

template <typename Type1>
Matrix<Type1>& Matrix<Type1>:: operator= (const Matrix& a) {
	if (this == &a)
		return *this;
	for (int i = 0; i < rows; i++)
		delete[] m[i];
	delete[] m;

	this->rows = a.rows;
	this->cols = a.cols;
	m = new Type1 * [rows];
	for (int i = 0; i < rows; i++)
		m[i] = new Type1[cols];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m[i][j] = a.m[i][j];
		}
	}
	return*this;
}

template <typename Type4>
bool Matrix<Type4>:: operator==(const Matrix<Type4>& a) {
	if (this->rows != a.rows || this->cols != a.cols)
		return false;
	else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (m[i][j] != a.m[i][j])
					return false;
			}
		}
	}
	return true;
}

template <typename Type3>
Type3*& Matrix<Type3>:: operator[] (const int index) {
	if (index >= cols || index >= rows || index < 0)
		cout << "Error operator []" << endl;
	else return m[index];
}

template <typename Type6>
ostream& operator<< (ostream& os, const Matrix<Type6>& a) {
	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			os << a.m[i][j] << "\t";
		}
		os << endl;
	}
}

template <typename Type7>
istream& operator>> (istream& is, Matrix<Type7>& a) {
	if (a.rows == 0 || a.cols == 0) {
		cout << "Enter rows and cols" << endl;
		is >> a.rows;
		is >> a.cols;
	}
	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			is >> a.m[i][j];
		}
	}
	return is;
}

template <typename Type3>
Matrix<Type3>:: ~Matrix() {
	for (int i = 0; i < rows; i++)
		delete[] m[i];
	delete[] m;
}