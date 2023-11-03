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

    
    int r, c;

    cout << "������� ������ ������� 1 : " << endl;
    cout << "����� �����: " << endl;
    cin >> r;
    cout << "����� ��������: " << endl;
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
        case 1:                                          // ���� ���������� = � +
        {
            int r2, c2;
            cout << "������� ������ ������� 2 : " << endl;
            cout << "����� �����: " << endl;
            cin >> r2;
            cout << "����� ��������: " << endl;
            cin >> c2;
            Matrix matrix2(r2, c2);
            cin >> matrix2;
            Matrix result = matrix1 + matrix2;
            cout << result;

            break;
        }
        case 2:                                          // ���� ��������� +=
        {
            int r2, c2;
            cout << "������� ������ ������� 2 : " << endl;
            cout << "����� �����: " << endl;
            cin >> r2;
            cout << "����� ��������: " << endl;
            cin >> c2;
            Matrix matrix2(r2, c2);
            cin >> matrix2;
            
            matrix1 += matrix2;
            cout << matrix1;

            break;
        }
        case 3:                                          // ���� ��������� -
        {
            int r2, c2;
            cout << "������� ������ ������� 2 : " << endl;
            cout << "����� �����: " << endl;
            cin >> r2;
            cout << "����� ��������: " << endl;
            cin >> c2;
            Matrix matrix2(r2, c2);
            cin >> matrix2;

            Matrix result = matrix1 - matrix2;
            cout << result;

            break;
        }

        case 4:                                         // ���� ��������� ==
        {
            int r2, c2;
            cout << "������� ������ � �������� ������� ��� ���������" << endl;
            cout << "����� �����: " << endl;
            cin >> r2;
            cout << "����� ��������: " << endl;
            cin >> c2;
            Matrix matrix2(r2, c2);
            cin >> matrix2;

            if (matrix1 == matrix2)
            {
                cout << endl << "������� �����" << endl;
            }
            else
            {
                cout << endl << "������� �� �����" << endl;
            }

            break;
        }

        case 5:                                           // ���� ���������  []
        {
            cout << endl << "�������� ������� ��������, ������� ����� �����:" << endl;
            int num1, num2;
            cout << "������: ";
            cin >> num1;
            cout << "�������: ";
            cin >> num2;
            cout << "������� � �������� [" << num1 << ", " << num2 << "]  ���: " << matrix1[num1][num2] << endl;

            break;
        }

        case 6:
        {
            cout << endl << "����� ������ �������� �� ������ �����?" << endl;
            int elem;
            cin >> elem;

            if (matrix1.search_M(elem) != NULL)
            {
                cout << endl << "������� " << elem << " ����� ������: [" << matrix1.search_M(elem)[0] 
                     << ", " << matrix1.search_M(elem)[1] << "];" << endl;
            }
            else
            {
                cout << endl << "������ �������� ��� � �������!" << endl;
            }

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


	system("pause");
	return 0;
}
