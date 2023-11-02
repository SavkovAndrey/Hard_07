#pragma once
#include <iostream>

using namespace std;

class Matrix
{
private:

	int* matr;
	int size_M;

public:

	Matrix();                                          // ����������� �� ���������

	Matrix(const Matrix& other);                       // ����������� �����������

	Matrix(int size);                                  // ����������� � �����������

	~Matrix();                                         // ����������

	int getSize_M();                                   // ������

	void setSize_M(int size);                          // ������

	void input_M();                                    // ���� ������� � ����������

	void output_M();                                   // ����� ������� �� �����

	Matrix& operator =(const Matrix& other);           // ���������� ��������� =

	Matrix operator +(const Matrix& other);            // ���������� ��������� +

	Matrix& operator +=(int elem);                     // ���������� �������� � ����� ������� (���������� +=)

	Matrix& operator -(int key);                       // �������� �������� �� ����� (���������� -)

	bool operator ==(const Matrix& other);             // ���������� ��������� ==

	int& operator [](int elem);                        // ���������� ��������� []

	friend ostream& operator <<(ostream& os, Matrix& array);   // ���������� ��������� <<

	friend istream& operator >>(istream& es, Matrix& array);   // ���������� ��������� >>

	int search_M(int element);                         // ����� �������� � ������� (������� ��������������)

};