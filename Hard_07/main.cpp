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

    
    int m, a;

    cout << "Введите размер матрицы 1 : " << endl;
    cout << "Число строк: " << endl;
    cin >> m;
    cout << "Число столбцов: " << endl;
    cin >> a;

    Matrix matrix1(m, a);
    matrix1.input_M();
    matrix1.output_M();
    
    cout << "выведем конкретный элемент   " << matrix1[1][1] << endl;

   

    /*
    while (true)
    {
        menu();
        int n;
        cin >> n;

        switch (n)
        {
        case 1:
        {
            int s2;
            cout << "Введите размер массива 2 : " << endl;
            cin >> s2;
            Array arr2(s2);
            cin >> arr2;
            Array result = arr1 + arr2;
            cout << result;

            break;
        }

        case 2:
        {
            cout << "Какой элемент добавить в конец массива?" << endl;
            int num;
            cin >> num;
            arr1 += num;
            cout << "Итог:" << endl;
            cout << arr1;

            break;
        }
        case 3:
        {
            cout << "Элемент с каким номером удалить из массива?" << endl;
            int num;
            cin >> num;
            arr1 - num;
            cout << "Итог:" << endl;
            cout << arr1;

            break;
        }

        case 4:
        {
            cout << "Введите размер и элементы массива для сравнения" << endl;
            int s3;
            cin >> s3;
            Array arr3(s3);
            cin >> arr3;
            if (arr1 == arr3)
            {
                cout << endl << "Массивы равны" << endl;
            }
            else
            {
                cout << endl << "Массивы не равны" << endl;
            }

            break;
        }

        case 5:
        {
            cout << endl << "выберите индекс элемента, который нужно взять:" << endl;
            int num;
            cin >> num;
            cout << "Элемент с индексом " << num << " это: " << arr1[num] << endl;

            break;
        }

        case 6:
        {
            cout << endl << "номер какого элемента вы хотите найти?" << endl;
            int elem;
            cin >> elem;
            if (arr1.search(elem) >= 0)
            {
                cout << endl << "элемент " << elem << " имеет индекс: " << arr1.search(elem) << endl;
            }
            else
            {
                cout << endl << "Такого элемента нет в массиве!" << endl;
            }

            break;
        }

        case 7:
        {
            cout << "Массив был отсортирован по возрастанию, результат: " << endl;
            arr1.sort();
            cout << arr1;

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

    */

	system("pause");
	return 0;
}
