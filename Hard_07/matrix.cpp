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
	matr = new Array[size_M];

	for (int i = 0; i < size_M; i++)                 // устанавливаем размеры каждого
	{                                                // объекта Array (которые есть в матрице)
		matr[i] = Array(other.matr[i].getSize());    // через конструктор с параметрами
	}


	for (int i = 0; i < size_M; i++)                 // переносим старую матрицу в новую
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
			for (int j = 0; j < matr[i].getSize(); j++)
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

/*
//-------------------------- ДОБАВЛЕНИЕ ЭЛЕМЕНТА В КОНЕЦ МАССИВА (ПЕРЕГРУЗКА +=)

Array& Array::operator +=(int elem)
{
	Array buff(*this);                                    // создаем копию нашего массива

	delete[] this->arr;                                   // удаляем наш массив

	this->size = buff.size + 1;

	this->arr = new int[size];                            // создаем новый массив увеличенной длинны

	for (int i = 0; i < size - 1; i++)
	{
		this->arr[i] = buff.arr[i];
	}

	this->arr[size - 1] = elem;                           // переносим из буфера все элементы и в конце дописываем новый

	return *this;
}

//-------------------------- УДАЛЕНИЕ ЭЛЕМЕНТА ПО КЛЮЧУ (перегрузка -)

Array& Array::operator -(int key)
{
	Array temp(*this);                                   // создаем копию нашего массива

	delete[] this->arr;                                  // очищаем наш массив

	size = temp.size - 1;

	this->arr = new int[size];                           // создаем новый массив на 1 элемент меньше

	if (key <= temp.size)                                // проверяем , что выбран элемент не за пределами массива
	{
		for (int i = 0, j = 0; i < temp.size; i++)       // переносим из буфера все элементы (кроме элемента номер key)
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
		cout << endl << "ОШИБКА!!! Вы пытаетесь удалить не существующий элемент!!!" << endl;
		system("pause");
		exit(1);
	}
}

//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА ==

bool Array::operator ==(const Array& other)
{
	if (this->size == other.size)                       // если размеры равны, смотрим дальше
	{
		for (int i = 0; i < size; i++)
		{
			if (this->arr[i] != other.arr[i])           // поэлементно сравниваем, если хоть один элемент не равен - false
			{
				return false;
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

int& Array::operator [](int elem)          // int возвращаем по ссылке, что бы мы могли не только выводить, но и менять
{                                          // перегрузив оператор [], мы можем через него менять элементы:
	return arr[elem];                      // cout << arr1[2] << endl;    cin >> arr1[2];
}


//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА <<

ostream& operator <<(ostream& os, Array& array)
{
	cout << "Массив:" << endl;
	for (int i = 0; i < array.size; i++)
	{
		os << setw(4) << array.arr[i];
	}
	cout << endl;

	return os;                                        // можно использовать:  Cout << arr1;
}

//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА >>

istream& operator >>(istream& es, Array& array)
{
	for (int i = 0; i < array.size; i++)
	{
		cout << "Введите " << i + 1 << "-й элемент массива: ";
		es >> array.arr[i];
	}
	cout << endl;

	return es;                                      // можно использовать:  cin >> arr1;
}

//-------------------------- ПОИСК ЭЛЕМЕНТА МАССИВА (ПЕРВОГО ВСТРЕТИВШЕГОСЯ)

int Array::search(int element)
{
	for (int i = 0; i < size; i++)            // перебираем элементы и ищем нужный нам
	{
		if (arr[i] == element)
		{
			return i;                         // возвращаем его номер , если нашли
		}
	}
	return -1;                                // если нет, возвращаем -1, как ошибку
}

//--------------------------
*/