#include <iostream>
#include <cstdlib>
#include <malloc.h>
#include "Matrix1.h"
#include "Vector1.h"
#include <vector>

int main() {
	Matrix<int> matr1;
	Matrix<int> matr2(5, 5);
	Matrix<int> matr3(matr2);
	cout << "rows3 : " << matr3.GetRows() << endl;
	cout << "cols3 : " << matr3.GetCols() << endl;
	cout << "matrix3 : " << matr3.GetMatrix()[0][0] << endl << endl;
	matr1.SetMatrix(3, 3);
	matr2.SetMatrix(3, 3);
	cout << "rows1 : " << matr1.GetRows() << endl;
	cout << "cols1 : " << matr1.GetCols() << endl;
	cout << "matrix1 : " << matr1.GetMatrix() << endl << endl;
	cout << "rows2 : " << matr2.GetRows() << endl;
	cout << "cols2 : " << matr1.GetCols() << endl;
	cout << "matrix2 : " << matr1.GetMatrix() << endl << endl;
	cout << "enter owe and two matrix" << endl;
	cin >> matr1 >> matr2;
	cout << "operator >> " << endl;
	cout << matr2[0][0] << "operator []" << endl;
	matr3 = matr1 + matr2;
	cout << "operator + " << matr3 << endl;
	matr3 = matr1 - matr2;
	cout << "operator - " << matr3 << endl;
	matr3 = matr1 * matr2;
	cout << "operator * " << matr3 << endl;
	bool equal = matr1 == matr2;
	cout << "operator == " << equal << endl;
	Vector<double>Vec1;
	Vector<double>Vec2(1, 5);
	Vector<double>Vec3(Vec2);
	matr1.SetMatrix(3, 3);
	Vector<double> Vec4(1, 3);
	Matrix<int> matr4(3, 3);
	cout << "operator << " << Vec2 << endl;
	cout << "GetVector " << Vec2.GetVector()[0] << endl;
	cout << "operator [] " << Vec2[0] << endl;
	Vec1.SetCols2(1, 5);
	cout << "Enter one and two vector" << endl;
	cin >> Vec1 >> Vec2;
	cout << "operator / " << Vec1 / Vec2 << endl;
	Vec3 = Vec1 + Vec2;
	cout << "operator + " << Vec3 << endl;
	Vec1.SetCols2(1, 3);
	Vec4 = matr4 * Vec4;
	double tmp = Vec1 * Vec2;
	cout << Vec4;
	cout << tmp;
	Vector<double> Vec5(1, 10);
	cout << BubbleSort(Vec5) << endl;
	cout << InsertionSort(Vec5) << endl;
	cout << QuickSort(Vec5, 0, Vec5.GetCols() - 1) << endl;
	Matrix<int> matr6(1, 2);
	matr6[0][0] = 1;
	cout << matr6[0][0] << endl;

	cout << "QuickSort" << endl;
	vector<double> V1(1, 3);
	Vector<int> V2(1, 10);
	Matrix<int> M(10, 10);
	int j = 0;
	for (int i = 100; j < 3; i *= 2) {
		V2.SetCols2(1, i);
		UseVector(V2);
		clock_t start = clock();
		QuickSort(V2, 0, V2.GetCols() - 1);
		clock_t end = clock();
		V1[j] = (double)(end - start) / CLOCKS_PER_SEC;
		j++;
	}
	for (int i = 0; i < 3; i++) {
		cout << V1[i] << endl;
	}


}