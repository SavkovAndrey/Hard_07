#include <iostream>
#include "matrix.h"
#include "Array.h"
#include "function.h"

using namespace std;

//--------------------------- ������� --------------------------------
/*
�������� ����� �������(� ������ ������ ������� �
������ �������� ������ ������ �� ����������� �������).

� ������ ����������� ��������� ������ :

������������(�� ���������, � �����������, �����������;

����������;

���� � ����������, ����� �� �����(� ���� ������� ������ �
��� ������ ������������� �������� ���������� ����� � ������);

����� �������� �� �����.

� ���� �� ������, ����������� �������� :

+, += (�������� ������);
�(���������);
= (����������);
== (��������� �� ���������);
[] (������ �������� � �������� ��������).
*/
//----------------------------------------------------------------------

int main() {
	setlocale(LC_ALL, "RU");

    
    int m, a;

    cout << "������� ������ ������� 1 : " << endl;
    cout << "����� �����: " << endl;
    cin >> m;
    cout << "����� ��������: " << endl;
    cin >> a;

    Matrix matrix1(m, a);
    matrix1.input_M();
    matrix1.output_M();
    
    cout << "������� ���������� �������   " << matrix1[1][1] << endl;

   

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
            cout << "������� ������ ������� 2 : " << endl;
            cin >> s2;
            Array arr2(s2);
            cin >> arr2;
            Array result = arr1 + arr2;
            cout << result;

            break;
        }

        case 2:
        {
            cout << "����� ������� �������� � ����� �������?" << endl;
            int num;
            cin >> num;
            arr1 += num;
            cout << "����:" << endl;
            cout << arr1;

            break;
        }
        case 3:
        {
            cout << "������� � ����� ������� ������� �� �������?" << endl;
            int num;
            cin >> num;
            arr1 - num;
            cout << "����:" << endl;
            cout << arr1;

            break;
        }

        case 4:
        {
            cout << "������� ������ � �������� ������� ��� ���������" << endl;
            int s3;
            cin >> s3;
            Array arr3(s3);
            cin >> arr3;
            if (arr1 == arr3)
            {
                cout << endl << "������� �����" << endl;
            }
            else
            {
                cout << endl << "������� �� �����" << endl;
            }

            break;
        }

        case 5:
        {
            cout << endl << "�������� ������ ��������, ������� ����� �����:" << endl;
            int num;
            cin >> num;
            cout << "������� � �������� " << num << " ���: " << arr1[num] << endl;

            break;
        }

        case 6:
        {
            cout << endl << "����� ������ �������� �� ������ �����?" << endl;
            int elem;
            cin >> elem;
            if (arr1.search(elem) >= 0)
            {
                cout << endl << "������� " << elem << " ����� ������: " << arr1.search(elem) << endl;
            }
            else
            {
                cout << endl << "������ �������� ��� � �������!" << endl;
            }

            break;
        }

        case 7:
        {
            cout << "������ ��� ������������ �� �����������, ���������: " << endl;
            arr1.sort();
            cout << arr1;

            break;
        }
        case 0:
        {
            cout << endl << "�� ����� �� ���������." << endl;
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
