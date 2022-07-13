#pragma once
#include<cmath>
#include<iostream>
#include <cstdlib>
#define matrix Matrix
using namespace std;

#ifndef __ARRAYLIST__
template <class T>T** arrayList(int row, int col);
template <class T>void arraysRandomValue(T** arr, int row, int col, T range = 10);
#endif // !__ARRAYLIST__

template <typename T>
class Matrix
{
	T** mat;
	int r, c;
	void init();
	const int __MAX_SIZE__ = 0x20;
	T** structureMatrix();
	void notice(int val);
public:
	Matrix();
	Matrix(int tr, int tc);
	Matrix(T** arr, int tr, int tc);
	Matrix(int p, char tc);
	T Determinant();
	void showMatrix(bool stu = false);
	void setValue(T val, int tr, int tc);
	T getValue(int tr, int tc);
	int* getSize();
	Matrix<T> operator=(const Matrix<T>& m)const;
	Matrix<T> operator+(const Matrix<T>& m)const;
	Matrix<T> operator-(const Matrix<T>& m)const;
	Matrix<T> operator*(const Matrix<T>& m)const;
	void clear();
};

template <class T> inline Matrix<T>::Matrix() {
	this->r = 1;
	this->c = 1;
	this->mat = this->structureMatrix();
	mat[0][0] = 0;
}

template <class T> inline Matrix<T>::Matrix(int tr, int tc) {
	if (max(tr, tc) <= __MAX_SIZE__) {
		this->r = tr;
		this->c = tc;
		this->mat = this->structureMatrix();
		this->init();
	}
	else {
		Matrix<T>();
		this->notice(max(tr, tc));
	}
}

template <class T> inline Matrix<T>::Matrix(T** arr, int tr, int tc) {
	if (max(tr, tc) <= __MAX_SIZE__) {
		this->r = tr;
		this->c = tc;
		this->mat = arr;
	}
	else {
		Matrix<T>();
		this->notice(max(tr, tc));
	}
}

template <class T>
inline Matrix<T>::Matrix(int p, char tc) {
	if (p <= __MAX_SIZE__) {
		this->r = p;
		this->c = p;
		this->mat = this->structureMatrix();

		switch (tc) {
		case 'E': {
			this->init();
			for (int i = 0; i < p; i++) {
				this->mat[i][i] = 1;
			}
			break;
		}
		case 'O': {
			this->init();
			break;
		}
		default:
			break;
		}
	}
	else {
		Matrix<T>();
		this->notice(p);
	}
}

template<typename T>
inline T Matrix<T>::Determinant()
{
	if (this->r == this->c) {
		T res = 0;
		for (int i = 0; i < this->r; i++) {
			T temp = 1;
			for (int j = 0;j<this->r; j++) {
				temp *= (T)pow(-1, i + j) * this->mat[i][(j + i) % this->r];
			}
			res += temp;
		}
		return res;
	}
	else {
		return 0;
	}
}

template <class T> inline void
Matrix<T>::showMatrix(bool stu) {
	if (this->mat != nullptr) {
		if (max(r, c) > 1 && stu) {
			cout << "[";
			for (int i = 0; i < this->r; i++) {
				for (int j = 0; j < this->c; j++) {
					if (j < this->c - 1) {
						cout << mat[i][j] << ",";
					}
					else {
						cout << mat[i][j];
					}
				}
				if (i < this->r - 1) {
					cout << ";";
				}
			}
			cout << "]\n";
		}
		else if (max(r, c) > 1)
		{
			cout << "[\n";
			for (int i = 0; i < this->r; i++) {
				for (int j = 0; j < this->c; j++) {
					if (j < this->c - 1) {
						cout << " " << mat[i][j] << "   ";
					}
					else {
						cout << mat[i][j];
					}
				}
				if (i < this->r - 1) {
					cout << "\n";
				}
			}
			cout << "\n]\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
}

template<typename T>
inline void Matrix<T>::setValue(T val, int tr, int tc)
{
	if (tr < 1 || tc < 1) {
		throw "Index Out Of Bounds Exception!";
	}
	this->mat[tr - 1][tc - 1] = val;
}

template<typename T>
inline T Matrix<T>::getValue(int tr, int tc)
{
	if (tr < 0 || tc < 0) {
		return T();
	}
	return this->mat[tr][tc];
}

template<typename T>
inline int* Matrix<T>::getSize()
{
	int* res = new int[2];
	res[0] = this->r;
	res[1] = this->c;
	return res;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator=(const Matrix& m) const
{
	return m;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator+(const Matrix& m) const
{
	if (this->r == m.r && this->c == m.c) {
		Matrix<T> res(m.r, m.c);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < r; j++) {
				res.mat[i][j] = this->mat[i][j] + m.mat[i][j];
			}
		}
		return res;
	}
	else {
		return Matrix<T>();
	}
}

template<typename T>
inline Matrix<T> Matrix<T>::operator-(const Matrix& m) const
{
	if (this->r == m.r && this->c == m.c) {
		Matrix<T> res(m.r, m.c);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < r; j++) {
				res.mat[i][j] = this->mat[i][j] - m.mat[i][j];
			}
		}
		return res;
	}
	else {
		return Matrix<T>();
	}
}

template<typename T>
inline Matrix<T> Matrix<T>::operator*(const Matrix& m) const
{

	if (this->c == m.r) {
		Matrix<T>res(this->r, m.c);
		for (int i = 0; i < res.r; i++) {
			for (int j = 0; j < res.c; j++) {
				for (int k = 0; k < m.r; k++) {
					res.mat[i][j] += this->mat[i][k] * m.mat[k][j];
				}
			}
		}
		return res;
	}
	else {
		return Matrix<T>();
	}

}

template <class T> inline T**
Matrix<T>::structureMatrix() {
	T** arr = new T * [r];
	for (int i = 0; i < r; i++) {
		arr[i] = new T[c];
	}
	return arr;
}

template<typename T>
inline void Matrix<T>::notice(int val)
{
	cout << "<------------------------------------------>\n";
	cout << "|*|Matrix size exceeds standard!!!\n";
	cout << "|*|Standard maximum size is " << __MAX_SIZE__ << ".\n";
	cout << "|*|Actual size is " << val << ".\n";
	cout << "<------------------------------------------>\n";
}

template <class T> inline void
Matrix<T>::init(void) {
	for (int i = 0; i < this->r; i++) {
		for (int j = 0; j < this->c; j++) {
			mat[i][j] = 0;
		}
	}
}

template <class T> inline void
Matrix<T>::clear(void) {
	if (max(r, c) > 1) {
		this->init();
	}
	else
	{
		this->mat[0][0] = 0;
	}
}


template <class T>
T** arrayList(int row, int col) {
	T** arr = new T * [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new T[col];
	}
	return arr;
}

template <class T>
void arraysRandomValue(T** arr, int row, int col, T range) {
	if (arr != nullptr) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				arr[i][j] = rand() % range;
			}
		}
	}
	else {
		return;
	}
}