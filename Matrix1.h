#pragma once
#include <iostream>
using namespace std;
template <typename Type>
class Matrix {
	Type** m;
	int rows;
	int cols;
public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix& a);
	int GetRows() const;
	int GetCols() const;
	void SetRows(int rows);
	void SetCols(int cols);
	void SetMatrix(int rows, int cols);
	Type** GetMatrix();
	Matrix<Type> operator+ (const Matrix<Type>& a);
	Matrix<Type> operator- (const Matrix<Type>& a);
	Matrix<Type> operator* (const Matrix<Type>& a);
	Matrix& operator= (const Matrix& a);
	bool operator== (const Matrix<Type>& a);
	Type*& operator[] (const int index);
	template <typename Type>
	friend ostream& operator<< (ostream& os, const Matrix<Type>& a);
	template <typename Type>
	friend istream& operator>> (istream& is, Matrix<Type>& a);
	~Matrix();//
};