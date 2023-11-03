#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "Array.h"

//-------------------------- ГЕТТЕР
int Matrix::getSize_M()
{
	return(size_M);                             // число СТРОК
}

//-------------------------- СЕТТЕР

void Matrix::setSize_M(int size)
{
	this->size_M = size;                        // число СТРОК
}

//-------------------------- КОНСТРУКТОР ПО УМОЛЧАНИЮ   


Matrix::Matrix()
{
	this->size_M = 1;                       // по умолчанию матрица из одного элемента
	matr = new Array[size_M];               // создаем матрицу типа Array

	for (int i = 0; i < size_M; i++)
	{
		matr[i] = Array();                  // для каждой "строки" создаем МАССИВ (по умолчанию) 
	}

	for (int i = 0; i < size_M; i++)
	{
		for (int j = 0; j < size_M; j++)
		{
		matr[i][j] = 0;                     // заполняем 0
		}
	}
}

//-------------------------- КОНСТРУКТОР КОПИРОВАНИЯ

Matrix::Matrix(const Matrix& other)
{
	this->size_M = other.size_M;

	this->matr = new Array[other.size_M];

	for (int i = 0; i < other.size_M; i++)                 // устанавливаем размеры каждого
	{                                                // объекта Array (которые есть в матрице)
		matr[i] = Array(other.matr[i].getSize());    // через конструктор с параметрами
	}


	for (int i = 0; i < other.size_M; i++)                 // переносим старую матрицу в новую
	{
		for (int j = 0; j < other.matr[i].getSize(); j++)
		{
		matr[i][j] = other.matr[i][j];
		}
	}
}

//-------------------------- КОНСТРУКТОР С ПАРАМЕТРАМИ

Matrix::Matrix(int size_M, int size_A)
{
	this->size_M = size_M;
	matr = new Array[size_M];

	for (int i = 0; i < size_M; i++)
	{
		matr[i] = Array(size_A);              // в каждом объекте matr создаем объект Array 
	}                                         // с нужным числом элементов

}

//-------------------------- ДЕСТРУКТОР

Matrix::~Matrix()
{
	delete[] matr;
}

//-------------------------- ВВОД МАССИВА С КЛАВИАТУРЫ

void Matrix::input_M()
{
	cout << endl;
	for (int i = 0; i < size_M; i++)
	{
		for (int j = 0; j < matr[i].getSize(); j++)
		{
		cout << "введите [" << i << ", " << j << "]" << " элемент массива: ";

		cin >> matr[i][j];
		}
	}
	cout << endl;
}

//-------------------------- ВЫВОД МАССИВА НА ЭКРАН

void Matrix::output_M()
{
	cout << "Матрица:" << endl;
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

//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА =

Matrix& Matrix::operator =(const Matrix& other)
{
	this->size_M = other.size_M;                     // берем нашему размеру, размер присваеваемого

	if (this->matr != nullptr)                       // очищаем наш массив, если он не пуст
	{
		delete[] this->matr;
	}

	this->matr = new Array[size_M];            // выделяем нашему массиву память (что бы влез присваеваемый)

	for (int i = 0; i < size_M; i++)                 // создаем в каждом элементе объект Array
	{
		matr[i] = Array(other.matr[i].getSize());    // размер каждого Array берем от "другого" Array
	}

	for (int i = 0; i < size_M; i++)              // переносим в наш массив пресваеваемый массив
	{
		for (int j = 0; j < matr[i].getSize(); j++)
		{
		this->matr[i][j] = other.matr[i][j];
		}
	}

	return *this;                                     // возвращаем разименованный указатель на наш объект
}
//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА +

Matrix Matrix::operator +(const Matrix& other)
{
		    //  сравниваем размеры слогаемых матриц (и ПОД-МАТРИЦ, только 0-ой элем, так как
	        //  ПОД-МАТРИЦЫ все одинаковы в рамках одной матрицы

	if ( (this->size_M == other.size_M) && (this->matr[0].getSize() == other.matr[0].getSize()) )  
	{
		Matrix result(size_M, matr->getSize());           // создаем результирующую матрицу

		for (int i = 0; i < size_M; i++)              // заполняем результирующую суммой 
		{
			for (int j = 0; j < matr[i].getSize(); j++)      // можно сократить , как в +=
			{
			result.matr[i][j] = this->matr[i][j] + other.matr[i][j];
			}
		}

		return result;                                    // возвращаем результирующую
	}
	else                                                  // если матрицы не равны: пишем ошибку, завершаем программу
	{
		cout << endl << "ОШИБКА!!! Вы пытаетесь сложить матрицы разных размеров!!! " << endl;
		system("pause");
		exit(1);
	}
}

//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА +=

Matrix& Matrix::operator +=(const Matrix& other)
{
	if ((this->size_M == other.size_M) && (this->matr[0].getSize() == other.matr[0].getSize()))
	{
		for (int i = 0; i < size_M; i++)
		{
			matr[i] = matr[i] + other.matr[i];     // Мы МОЖЕМ СДЕЛАТЬ ТАК !!!
		}                                          // так как у нас перегружен оператор + для Array

		return *this;
	}
	else                      // если матрицы не равны: пишем ошибку, завершаем программу
	{
		cout << endl << "ОШИБКА!!! Вы пытаетесь сложить матрицы разных размеров!!! " << endl;
		system("pause");
		exit(1);
	}
}

//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА -

Matrix Matrix::operator -(const Matrix& other)                      // ВАЖНО! передача ПО ЗНАЧЕНИЮ ( не по ссылке)
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
	else                      // если матрицы не равны: пишем ошибку, завершаем программу
	{
		cout << endl << "ОШИБКА!!! Вы пытаетесь отнять матрицы разных размеров!!! " << endl;
		system("pause");
		exit(1);
	}
}

//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА ==

bool Matrix::operator ==(const Matrix& other)
{
	if ((this->size_M == other.size_M) && (matr->getSize() == other.matr->getSize()))   // если размеры равны, смотрим дальше
	{
		for (int i = 0; i < size_M; i++)
		{
			for (int j = 0; j < matr->getSize(); j++)
			{
			    if (this->matr[i][j] != other.matr[i][j])      // поэлементно сравниваем, если хоть один элемент не равен - false
			    {                                              // matr[i] != other.matr[i] , так нельзя , так как у класса
				return false;                                  // Array не перегружен оператор !=
			    } 
			}
		}

		return true;
	}
	else                                                // если размеры не равны - false
	{
		return false;
	}
}

//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА []

Array Matrix::operator [](int elem)          // вернет объект класса Array (а не конкретный элемент!)
{                                           
	return matr[elem];                      // martix1[1][1] венет нам объект Array из ячейки 1 , а затем вернет из
}                                           // объекта Array 1 элемент ( так как у класса Array перегружен оператор [])


//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА <<

ostream& operator <<(ostream& os, Matrix& matrix)
{
	cout << "Матрица:" << endl;
	for (int i = 0; i < matrix.size_M; i++)
	{
		os << setw(4) << matrix.matr[i];
	}
	cout << endl;

	return os;                                        // можно использовать:  Cout << arr1;
}

//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА >>

istream& operator >>(istream& es, Matrix& matrix)
{
	for (int i = 0; i < matrix.size_M; i++)
	{
		cout << "Введите " << i + 1 << "-й массив матрицы: " << endl;
		es >> matrix.matr[i];
	}
	cout << endl;

	return es;                                      // можно использовать:  cin >> arr1;
}

//-------------------------- ПОИСК ЭЛЕМЕНТА МАССИВА (ПЕРВОГО ВСТРЕТИВШЕГОСЯ)

int* Matrix::search_M(int element)
{
	int position[2]{ 0 };                          // массив для хранения координат найденного элемента

	for (int i = 0; i < size_M; i++)               // перебираем элементы и ищем нужный нам
	{
		for (int j = 0; j < matr->getSize(); j++)
		{
		if (matr[i][j] == element)
		{
			position[0] = i;
			position[1] = j;
			return position;                       // возвращаем массив с двумя координатами
		}
		}
	}
	return NULL;                                   // если нет, возвращаем пустой массив
}
// пример применения: 
// cout << "позиция искомого элемента (60) равна: [" << matrix1.search_M(30)[0] << ", " << matrix1.search_M(30)[1] << "]" << endl;
//--------------------------
