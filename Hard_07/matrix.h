#pragma once
#include <iostream>
#include "Array.h"

using namespace std;

class Matrix
{
private:

	Array* matr;                                       // ��������� �� ������� ���� Array
	int size_M;

public:

	Matrix();                                          // ����������� �� ���������

	Matrix(const Matrix& other);                       // ����������� �����������

	Matrix(int size_M, int size_A);                                  // ����������� � �����������

	~Matrix();                                         // ����������

	int getSize_M();                                   // ������

	void setSize_M(int size);                          // ������

	void input_M();                                    // ���� ������� � ����������

	void output_M();                                   // ����� ������� �� �����

	Matrix& operator =(const Matrix& other);           // ���������� ��������� =

	Matrix operator +(const Matrix& other);            // ���������� ��������� +

	Matrix& operator +=(const Matrix& other);          // ���������� += (������� � ���������)
	
	Matrix operator -(const Matrix& other);            // ���������� - (��������� ������)

	bool operator ==(const Matrix& other);             // ���������� ��������� ==

	Array operator [](int elem);                       // ���������� ��������� []   �����: ������ ��� ������ ������ Array (� �� int)

	friend ostream& operator <<(ostream& os, Matrix& matrix);   // ���������� ��������� <<

	friend istream& operator >>(istream& es, Matrix& matrix);   // ���������� ��������� >>

	int* search_M(int element);                        // ����� �������� � ������� (������� ��������������)
	
};