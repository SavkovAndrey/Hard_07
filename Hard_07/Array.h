#pragma once
#include <iostream>

using namespace std;

class Array
{
private:

	int* arr;
	int size;

public:

	Array();                                         // конструктор по умолчанию

	Array(const Array& other);                       // конструктор копирования

	Array(int size);                                 // конструктор с параметрами

	~Array();                                        // деструктор

	int getSize();                                   // геттер

	void setSize(int size);                          // сеттер

	void input();                                    // ввод массива с клавиатуры

	void output();                                   // вывод массива на экран

	Array& operator =(const Array& other);           // перегрузка оператора =

	Array operator +(const Array& other);            // перегрузка оператора +

	Array& operator +=(int elem);                    // добавление элемента в конец массива (перегрузка +=)

	Array& operator -(int key);                      // удаление элемента по ключу (перегрузка -)

	bool operator ==(const Array& other);            // перегрузка оператора ==

	int& operator [](int elem);                      // перегрузка оператора []

	friend ostream& operator <<(ostream& os, Array& array);   // перегрузка оператора <<

	friend istream& operator >>(istream& es, Array& array);   // перегрузка оператора >>

	int search(int element);                         // поиск элемента в массиве (первого встретившегося)

	void sort();                                     // сортировка массива по возрастанию
};

