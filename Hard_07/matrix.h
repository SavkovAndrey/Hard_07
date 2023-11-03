#pragma once
#include <iostream>
#include "Array.h"

using namespace std;

class Matrix
{
private:

	Array* matr;                                       // указатель на матрицу типа Array
	int size_M;

public:

	Matrix();                                          // конструктор по умолчанию

	Matrix(const Matrix& other);                       // конструктор копирования

	Matrix(int size_M, int size_A);                                  // конструктор с параметрами

	~Matrix();                                         // деструктор

	int getSize_M();                                   // геттер

	void setSize_M(int size);                          // сеттер

	void input_M();                                    // ввод массива с клавиатуры

	void output_M();                                   // вывод массива на экран

	Matrix& operator =(const Matrix& other);           // перегрузка оператора =

	Matrix operator +(const Matrix& other);            // перегрузка оператора +

	Matrix& operator +=(const Matrix& other);          // перегрузка += (сложить и присвоить)
	
	Matrix operator -(const Matrix& other);            // перегрузка - (вычитание матриц)

	bool operator ==(const Matrix& other);             // перегрузка оператора ==

	Array operator [](int elem);                       // перегрузка оператора []   ВАЖНО: вернет нам объект класса Array (а не int)

	friend ostream& operator <<(ostream& os, Matrix& matrix);   // перегрузка оператора <<

	friend istream& operator >>(istream& es, Matrix& matrix);   // перегрузка оператора >>

	int* search_M(int element);                        // поиск элемента в массиве (первого встретившегося)
	
};