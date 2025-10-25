#include <iostream>

using namespace std;

int maxsum = 0, nomer = 0;

int main()
{
    setlocale(LC_ALL, "Russian");




    cout << "ПУНКТ 1" << endl;

    int arr[6];
    bool povt = false;

    for (int i = 0; i < 6; ++i) {
        cout << "Введите " << i << "-й элемент массива >> ";
        cin >> arr[i];
    }

    for (int i = 0; i < 5; ++i) {
        if (arr[i] == arr[i + 1]) {
            povt = true;
            break;
        }
    }

    if (povt) {
        for (int i = 0; i < 5; ++i) {
            for (int j = i + 1; j < 6; ++j) {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
        cout << "\nВ массиве есть пара одинаковых чисел подряд, поэтому он был отсортирован по возрастанию" << endl;
    }
    else {
        cout << "В массиве нет пар одинаковых чисел подряд, поэтому он остался неизменным" << endl;
    }

    cout << "Элементы массива:";
    for (int i = 0; i < 6; ++i) {
        cout << " " << arr[i];
    }



    cout << "\n\nПУНКТ 2" << endl;


    int matr[3][4];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << i + 1 << " строка, " << j + 1 << "-й столбец >> ";
            cin >> matr[i][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (abs(matr[i][0]) + abs(matr[i][1]) + abs(matr[i][2]) + abs(matr[i][3]) > maxsum) {
            nomer = i;
            maxsum = abs(matr[i][0]) + abs(matr[i][1]) + abs(matr[i][2]) + abs(matr[i][3]);
        }
    }

    for (int i = 0; i < 4; ++i) {
        matr[nomer][i] = 0;
    }

    cout << "Полученная матрица:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << "[" << matr[i][j] << "]";
        }
        cout << "\n";
    }
}
