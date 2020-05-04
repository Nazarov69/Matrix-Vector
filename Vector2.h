#include "Vector1.h"

template <typename Type21>
Type21* Vector<Type21> ::GetVector() {
	return SetMatrix()[0];
}

template <typename Type21>
void Vector<Type21> ::SetCols2(int rows3, int cols3) {
	SetMatrix(1, cols3);
}

template <typename Type38>
Vector<Type38> Vector<Type38> :: operator+ (const Vector<Type38>& b) {
	if (this->GetCols2() == b.GetCols2()) {
		Vector<Type38> Vec(this);
		for (int i = 0; i < Vec.GetCols2(); i++) {
			Vec.GetVector()[i] = this->GetVector()[i] + b[i];
		}
		return Vec;
	}
	else cout << "Error operator + vector" << endl;
}

template <typename Type37>
Vector<Type37> Vector<Type37> :: operator/ (const Vector<Type37>& b) {
	if (this->GetCols2() == b.GetCols2()) {
		Vector<Type37> Vec(this);
		for (int i = 0; i < Vec.GetCols2(); i++) {
			if (b[i] != 0)
				Vec.GetVector()[i] = Vec.GetVector()[i] / b[i];
		}
		return Vec;
	}
	else cout << "Error operator / vector" << endl;
}

template <typename Type36>
Type36 Vector<Type36> :: operator* (const Vector<Type36>& b) {
	if (this->GetCols2() == b.GetCols2()) {
		Type36 Vec = 0;
		for (int i = 0; i < b.GetCols2(); i++)
			Vec = Vec + this->GetVector()[i] * b.GetVector[i];
		return Vec;
	}
	else cout << "Error operator * vector" << endl;
}

template<typename Type34>
istream& operator >>(istream& is, Vector<Type34>& b) {
	if (b.GetCols2() == 0) {
		int cols2;
		is >> cols2;
		b.SetCols2(cols2);
	}
	for (int i = 0; i < b.GetCols2(); i++)
		is >> b.GetVector()[i];
	return is;
}

template<typename Type35>
Type35& Vector<Type35> :: operator[] (const int index) {
	return GetVector()[index];
}

template<typename Type31>
clock_t BubbleSort(Vector<Type31>& a) {
	clock_t one, two;
	Type31 c = 0;
	one = clock();
	for (int i = 0; i < a.GetCols2(); i++) {
		for (int j = 0; j < i; j++) {
			if (a.GetVector()[j] > a.GetVector()[j + 1]) {
				c = a.GetVector()[j];
				a.GetVector()[j] = a.GetVector()[j + 1];
				a.GetVector()[j + 1] = c;
			}
		}
	}
	two = clock();
	return (two - one);
}

template<typename Type32>
clock_t InsertionSort(Vector<Type32>& a) {
	clock_t one, two;
	Type32 c;
	int ind;
	one = clock();
	for (int i = 1; i < a.GetCols2(); i++) {
		c = a.GetVector()[i];
		ind = i - 1;
		while (ind >= 0 && a.GetVector()[ind] > c) {
			a.GetVector[ind + 1] = a.GetVector()[ind];
			ind -= 1;
		}
		a.GetVector()[ind + 1] = c;
	}
	two = clock();
	return(two - one);
}

template<typename Type33>
clock_t QuickSort(Vector<Type33>& a, int l, int r) {
	clock_t one, two, three;
	Type33 c;
	int ll = l;
	int rr = r;
	one = clock();
	Type33 d = a.GetVector()[(ll + rr) / 2];
	do {
		while (a.GetVector()[ll] < d)
			ll++;
		while (a.GetVector()[rr] > d)
			rr--;
		if (ll <= rr) {
			if (ll < rr) {
				c = a.GetVector()[ll];
				a.GetVector()[ll] = a.GetVector()[rr];
				a.GetVector()[rr] = c;
			}
			ll++;
			rr--;
		}
	} while (ll <= rr);
	if (ll < r)
		three = QuickSort(a, ll, r);
	if (l < rr)
		three = QuickSort(a, l, rr);
	two = clock();
	return(two - one);
}
