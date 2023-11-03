#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "Array.h"

//-------------------------- ������
int Matrix::getSize_M()
{
	return(size_M);                             // ����� �����
}

//-------------------------- ������

void Matrix::setSize_M(int size)
{
	this->size_M = size;                        // ����� �����
}

//-------------------------- ����������� �� ���������   


Matrix::Matrix()
{
	this->size_M = 1;                       // �� ��������� ������� �� ������ ��������
	matr = new Array[size_M];               // ������� ������� ���� Array

	for (int i = 0; i < size_M; i++)
	{
		matr[i] = Array();                  // ��� ������ "������" ������� ������ (�� ���������) 
	}

	for (int i = 0; i < size_M; i++)
	{
		for (int j = 0; j < size_M; j++)
		{
		matr[i][j] = 0;                     // ��������� 0
		}
	}
}

//-------------------------- ����������� �����������

Matrix::Matrix(const Matrix& other)
{
	this->size_M = other.size_M;
	matr = new Array[size_M];

	for (int i = 0; i < size_M; i++)                 // ������������� ������� �������
	{                                                // ������� Array (������� ���� � �������)
		matr[i] = Array(other.matr[i].getSize());    // ����� ����������� � �����������
	}


	for (int i = 0; i < size_M; i++)                 // ��������� ������ ������� � �����
	{
		for (int j = 0; j < other.matr[i].getSize(); j++)
		{
		matr[i][j] = other.matr[i][j];
		}
	}
}

//-------------------------- ����������� � �����������

Matrix::Matrix(int size_M, int size_A)
{
	this->size_M = size_M;
	matr = new Array[size_M];

	for (int i = 0; i < size_M; i++)
	{
		matr[i] = Array(size_A);              // � ������ ������� matr ������� ������ Array 
	}                                         // � ������ ������ ���������

}

//-------------------------- ����������

Matrix::~Matrix()
{
	delete[] matr;
}

//-------------------------- ���� ������� � ����������

void Matrix::input_M()
{
	cout << endl;
	for (int i = 0; i < size_M; i++)
	{
		for (int j = 0; j < matr[i].getSize(); j++)
		{
		cout << "������� [" << i << ", " << j << "]" << " ������� �������: ";

		cin >> matr[i][j];
		}
	}
	cout << endl;
}

//-------------------------- ����� ������� �� �����

void Matrix::output_M()
{
	cout << "�������:" << endl;
	for (int i = 0; i < size_M; i++)
	{
		for (int j = 0; j < matr[i].getSize(); j++)
		{
		cout << matr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

//-------------------------- ���������� ��������� =

Matrix& Matrix::operator =(const Matrix& other)
{
	this->size_M = other.size_M;                     // ����� ������ �������, ������ ��������������

	if (this->matr != nullptr)                       // ������� ��� ������, ���� �� �� ����
	{
		delete[] this->matr;
	}

	this->matr = new Array[size_M];            // �������� ������ ������� ������ (��� �� ���� �������������)

	for (int i = 0; i < size_M; i++)                 // ������� � ������ �������� ������ Array
	{
		matr[i] = Array(other.matr[i].getSize());    // ������ ������� Array ����� �� "�������" Array
	}

	for (int i = 0; i < size_M; i++)              // ��������� � ��� ������ ������������� ������
	{
		for (int j = 0; j < matr[i].getSize(); j++)
		{
		this->matr[i][j] = other.matr[i][j];
		}
	}

	return *this;                                     // ���������� �������������� ��������� �� ��� ������
}
//-------------------------- ���������� ��������� +

Matrix Matrix::operator +(const Matrix& other)
{
		    //  ���������� ������� ��������� ������ (� ���-������, ������ 0-�� ����, ��� ���
	        //  ���-������� ��� ��������� � ������ ����� �������

	if ( (this->size_M == other.size_M) && (this->matr[0].getSize() == other.matr[0].getSize()) )  
	{
		Matrix result(size_M, matr->getSize());           // ������� �������������� �������

		for (int i = 0; i < size_M; i++)              // ��������� �������������� ������ 
		{
			for (int j = 0; j < matr[i].getSize(); j++)
			{
			result.matr[i][j] = this->matr[i][j] + other.matr[i][j];
			}
		}

		return result;                                    // ���������� ��������������
	}
	else                                                  // ���� ������� �� �����: ����� ������, ��������� ���������
	{
		cout << endl << "������!!! �� ��������� ������� ������� ������ ��������!!! " << endl;
		system("pause");
		exit(1);
	}
}

/*
//-------------------------- ���������� �������� � ����� ������� (���������� +=)

Array& Array::operator +=(int elem)
{
	Array buff(*this);                                    // ������� ����� ������ �������

	delete[] this->arr;                                   // ������� ��� ������

	this->size = buff.size + 1;

	this->arr = new int[size];                            // ������� ����� ������ ����������� ������

	for (int i = 0; i < size - 1; i++)
	{
		this->arr[i] = buff.arr[i];
	}

	this->arr[size - 1] = elem;                           // ��������� �� ������ ��� �������� � � ����� ���������� �����

	return *this;
}

//-------------------------- �������� �������� �� ����� (���������� -)

Array& Array::operator -(int key)
{
	Array temp(*this);                                   // ������� ����� ������ �������

	delete[] this->arr;                                  // ������� ��� ������

	size = temp.size - 1;

	this->arr = new int[size];                           // ������� ����� ������ �� 1 ������� ������

	if (key <= temp.size)                                // ��������� , ��� ������ ������� �� �� ��������� �������
	{
		for (int i = 0, j = 0; i < temp.size; i++)       // ��������� �� ������ ��� �������� (����� �������� ����� key)
		{
			if (i + 1 != key)
			{
				this->arr[j] = temp.arr[i];
				j++;
			}
		}

		return *this;
	}
	else
	{
		cout << endl << "������!!! �� ��������� ������� �� ������������ �������!!!" << endl;
		system("pause");
		exit(1);
	}
}

//-------------------------- ���������� ��������� ==

bool Array::operator ==(const Array& other)
{
	if (this->size == other.size)                       // ���� ������� �����, ������� ������
	{
		for (int i = 0; i < size; i++)
		{
			if (this->arr[i] != other.arr[i])           // ����������� ����������, ���� ���� ���� ������� �� ����� - false
			{
				return false;
			}
		}

		return true;
	}
	else                                                // ���� ������� �� ����� - false
	{
		return false;
	}
}

//-------------------------- ���������� ��������� []

int& Array::operator [](int elem)          // int ���������� �� ������, ��� �� �� ����� �� ������ ��������, �� � ������
{                                          // ���������� �������� [], �� ����� ����� ���� ������ ��������:
	return arr[elem];                      // cout << arr1[2] << endl;    cin >> arr1[2];
}


//-------------------------- ���������� ��������� <<

ostream& operator <<(ostream& os, Array& array)
{
	cout << "������:" << endl;
	for (int i = 0; i < array.size; i++)
	{
		os << setw(4) << array.arr[i];
	}
	cout << endl;

	return os;                                        // ����� ������������:  Cout << arr1;
}

//-------------------------- ���������� ��������� >>

istream& operator >>(istream& es, Array& array)
{
	for (int i = 0; i < array.size; i++)
	{
		cout << "������� " << i + 1 << "-� ������� �������: ";
		es >> array.arr[i];
	}
	cout << endl;

	return es;                                      // ����� ������������:  cin >> arr1;
}

//-------------------------- ����� �������� ������� (������� ��������������)

int Array::search(int element)
{
	for (int i = 0; i < size; i++)            // ���������� �������� � ���� ������ ���
	{
		if (arr[i] == element)
		{
			return i;                         // ���������� ��� ����� , ���� �����
		}
	}
	return -1;                                // ���� ���, ���������� -1, ��� ������
}

//--------------------------
*/