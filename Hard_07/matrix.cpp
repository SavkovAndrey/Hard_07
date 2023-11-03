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

	this->matr = new Array[other.size_M];

	for (int i = 0; i < other.size_M; i++)                 // ������������� ������� �������
	{                                                // ������� Array (������� ���� � �������)
		matr[i] = Array(other.matr[i].getSize());    // ����� ����������� � �����������
	}


	for (int i = 0; i < other.size_M; i++)                 // ��������� ������ ������� � �����
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
			for (int j = 0; j < matr[i].getSize(); j++)      // ����� ��������� , ��� � +=
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

//-------------------------- ���������� ��������� +=

Matrix& Matrix::operator +=(const Matrix& other)
{
	if ((this->size_M == other.size_M) && (this->matr[0].getSize() == other.matr[0].getSize()))
	{
		for (int i = 0; i < size_M; i++)
		{
			matr[i] = matr[i] + other.matr[i];     // �� ����� ������� ��� !!!
		}                                          // ��� ��� � ��� ���������� �������� + ��� Array

		return *this;
	}
	else                      // ���� ������� �� �����: ����� ������, ��������� ���������
	{
		cout << endl << "������!!! �� ��������� ������� ������� ������ ��������!!! " << endl;
		system("pause");
		exit(1);
	}
}

//-------------------------- ���������� ��������� -

Matrix Matrix::operator -(const Matrix& other)                      // �����! �������� �� �������� ( �� �� ������)
{
	if ((this->size_M == other.size_M) && (matr->getSize() == other.matr->getSize()))
	{
		Matrix result(size_M, matr->getSize());

		for (int i = 0; i < size_M; i++)
		{
			for (int j = 0; j < matr[i].getSize(); j++)
			{
			result.matr[i][j] = matr[i][j] - other.matr[i][j];     
			}
		}                                         

		return result;
	}
	else                      // ���� ������� �� �����: ����� ������, ��������� ���������
	{
		cout << endl << "������!!! �� ��������� ������ ������� ������ ��������!!! " << endl;
		system("pause");
		exit(1);
	}
}

//-------------------------- ���������� ��������� ==

bool Matrix::operator ==(const Matrix& other)
{
	if ((this->size_M == other.size_M) && (matr->getSize() == other.matr->getSize()))   // ���� ������� �����, ������� ������
	{
		for (int i = 0; i < size_M; i++)
		{
			for (int j = 0; j < matr->getSize(); j++)
			{
			    if (this->matr[i][j] != other.matr[i][j])      // ����������� ����������, ���� ���� ���� ������� �� ����� - false
			    {                                              // matr[i] != other.matr[i] , ��� ������ , ��� ��� � ������
				return false;                                  // Array �� ���������� �������� !=
			    } 
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

Array Matrix::operator [](int elem)          // ������ ������ ������ Array (� �� ���������� �������!)
{                                           
	return matr[elem];                      // martix1[1][1] ����� ��� ������ Array �� ������ 1 , � ����� ������ ��
}                                           // ������� Array 1 ������� ( ��� ��� � ������ Array ���������� �������� [])


//-------------------------- ���������� ��������� <<

ostream& operator <<(ostream& os, Matrix& matrix)
{
	cout << "�������:" << endl;
	for (int i = 0; i < matrix.size_M; i++)
	{
		os << setw(4) << matrix.matr[i];
	}
	cout << endl;

	return os;                                        // ����� ������������:  Cout << arr1;
}

//-------------------------- ���������� ��������� >>

istream& operator >>(istream& es, Matrix& matrix)
{
	for (int i = 0; i < matrix.size_M; i++)
	{
		cout << "������� " << i + 1 << "-� ������ �������: " << endl;
		es >> matrix.matr[i];
	}
	cout << endl;

	return es;                                      // ����� ������������:  cin >> arr1;
}

//-------------------------- ����� �������� ������� (������� ��������������)

int* Matrix::search_M(int element)
{
	int position[2]{ 0 };                          // ������ ��� �������� ��������� ���������� ��������

	for (int i = 0; i < size_M; i++)               // ���������� �������� � ���� ������ ���
	{
		for (int j = 0; j < matr->getSize(); j++)
		{
		if (matr[i][j] == element)
		{
			position[0] = i;
			position[1] = j;
			return position;                       // ���������� ������ � ����� ������������
		}
		}
	}
	return NULL;                                   // ���� ���, ���������� ������ ������
}
// ������ ����������: 
// cout << "������� �������� �������� (60) �����: [" << matrix1.search_M(30)[0] << ", " << matrix1.search_M(30)[1] << "]" << endl;
//--------------------------
