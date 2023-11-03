#include <iostream>
#include "matrix.h"
#include "Array.h"
#include "function.h"

using namespace std;

//--------------------------- ЗАДАНИЕ --------------------------------
/*
Написать класс Матрица(в данном случае матрица –
массив объектов класса Массив из предыдущего задания).

В классе реализовать следующие методы :

конструкторы(по умолчанию, с параметрами, копирования;

деструктор;

ввод с клавиатуры, вывод на экран(в виде методов класса и
при помощи перегруженных операций потокового ввода и вывода);

поиск элемента по ключу.

В этом же классе, перегрузить операции :

+, += (сложение матриц);
–(вычитание);
= (присвоение);
== (сравнение по элементам);
[] (взятие элемента с заданным индексом).
*/
//----------------------------------------------------------------------

int main() {
	setlocale(LC_ALL, "RU");

    
    int r, c;

    cout << "Введите размер матрицы 1 : " << endl;
    cout << "Число строк: " << endl;
    cin >> r;
    cout << "Число столбцов: " << endl;
    cin >> c;

    Matrix matrix1(r, c);
    matrix1.input_M();
    matrix1.output_M();

    
    while (true)
    {
        menu();
        int n;
        cin >> n;

        switch (n)
        {
        case 1:                                          // ТЕСТ операторов = и +
        {
            int r2, c2;
            cout << "Введите размер матрицы 2 : " << endl;
            cout << "Число строк: " << endl;
            cin >> r2;
            cout << "Число столбцов: " << endl;
            cin >> c2;
            Matrix matrix2(r2, c2);
            cin >> matrix2;
            Matrix result = matrix1 + matrix2;
            cout << result;

            break;
        }
        case 2:                                          // ТЕСТ оператора +=
        {
            int r2, c2;
            cout << "Введите размер матрицы 2 : " << endl;
            cout << "Число строк: " << endl;
            cin >> r2;
            cout << "Число столбцов: " << endl;
            cin >> c2;
            Matrix matrix2(r2, c2);
            cin >> matrix2;
            
            matrix1 += matrix2;
            cout << matrix1;

            break;
        }
        case 3:                                          // ТЕСТ оператора -
        {
            int r2, c2;
            cout << "Введите размер матрицы 2 : " << endl;
            cout << "Число строк: " << endl;
            cin >> r2;
            cout << "Число столбцов: " << endl;
            cin >> c2;
            Matrix matrix2(r2, c2);
            cin >> matrix2;

            Matrix result = matrix1 - matrix2;
            cout << result;

            break;
        }

        case 4:                                         // ТЕСТ оператора ==
        {
            int r2, c2;
            cout << "Введите размер и элементы матрицы для сравнения" << endl;
            cout << "Число строк: " << endl;
            cin >> r2;
            cout << "Число столбцов: " << endl;
            cin >> c2;
            Matrix matrix2(r2, c2);
            cin >> matrix2;

            if (matrix1 == matrix2)
            {
                cout << endl << "Матрицы равны" << endl;
            }
            else
            {
                cout << endl << "Матрицы не равны" << endl;
            }

            break;
        }

        case 5:                                           // ТЕСТ оператора  []
        {
            cout << endl << "выберите индексы элемента, который нужно взять:" << endl;
            int num1, num2;
            cout << "Строка: ";
            cin >> num1;
            cout << "Столбец: ";
            cin >> num2;
            cout << "Элемент с индексом [" << num1 << ", " << num2 << "]  это: " << matrix1[num1][num2] << endl;

            break;
        }

        case 6:
        {
            cout << endl << "номер какого элемента вы хотите найти?" << endl;
            int elem;
            cin >> elem;

            if (matrix1.search_M(elem) != NULL)
            {
                cout << endl << "элемент " << elem << " имеет индекс: [" << matrix1.search_M(elem)[0] 
                     << ", " << matrix1.search_M(elem)[1] << "];" << endl;
            }
            else
            {
                cout << endl << "Такого элемента нет в массиве!" << endl;
            }

            break;
        }
       
        case 0:
        {
            cout << endl << "Вы вышли из программы." << endl;
            system("pause");
            return 0;
            break;
        }
        }


    }


	system("pause");
	return 0;
}
