#include "Matrix1.h"
#include <time.h>
#include <iostream>
using namespace std;
template <typename Type21>
class Vector : public Matrix<Type21> {
public:
	Vector() : Matrix() {}
	Vector(int rows, int cols) : Matrix(1, cols) {}
	Vector(const Vector& a) : Matrix(a) {}
	Type21* GetVector();
	void SetCols2(int rows3, int cols3);
	Vector<Type21> operator+ (const Vector<Type21>& b);
	Vector<Type21> operator/ (const Vector<Type21>& b);
	Type21 operator* (const Vector<Type21>& b);
	Type21& operator[] (const int index);
	template <typename Type34>
	friend istream& operator >>(istream& is, Vector<Type34>& b);
	friend void UseVector(Vector& a) {
		for (int i = 0; i < a.GetCols(); i++)
			a[i] = rand();
	}
	template<typename Type31>
	friend clock_t BubbleSort(Vector<Type31>& a);
	template<typename Type32>
	friend clock_t InsertionSort(Vector<Type32>& a);
	template<typename Type33>
	friend clock_t QuickSort(Vector<Type33>& a, int l, int r);
	~Vector() {}
};
