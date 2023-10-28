#pragma once
#include <iostream>

using namespace std;

class Array
{
private:

	int* arr;
	int size;

public:

	Array();                                         // ����������� �� ���������

	Array(const Array& other);                       // ����������� �����������

	Array(int size);                                 // ����������� � �����������

	~Array();                                        // ����������

	int getSize();                                   // ������

	void setSize(int size);                          // ������

	void input();                                    // ���� ������� � ����������

	void output();                                   // ����� ������� �� �����

	Array& operator =(const Array& other);           // ���������� ��������� =

	Array operator +(const Array& other);            // ���������� ��������� +

	Array& operator +=(int elem);                    // ���������� �������� � ����� ������� (���������� +=)

	Array& operator -(int key);                      // �������� �������� �� ����� (���������� -)

	bool operator ==(const Array& other);            // ���������� ��������� ==

	int& operator [](int elem);                      // ���������� ��������� []

	friend ostream& operator <<(ostream& os, Array& array);   // ���������� ��������� <<

	friend istream& operator >>(istream& es, Array& array);   // ���������� ��������� >>

	int search(int element);                         // ����� �������� � ������� (������� ��������������)

	void sort();                                     // ���������� ������� �� �����������
};

