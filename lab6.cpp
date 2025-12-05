#include <iostream>
#include <cstdlib>

using namespace std;

int* findZeroStolb(int** arr, int strk, int stlb, int& сount) {
    int* result = (int*)malloc(stlb * sizeof(int));
    сount = 0;

    for (int j = 0; j < stlb; j++) {
        bool hasZero = false;

        for (int i = 0; i < strk; i++) {
            if (arr[i][j] == 0) {
                hasZero = true;
                break;
            }
        }

        if (hasZero) {
            result[сount++] = j;
        }
    }

    result = (int*)realloc(result, сount * sizeof(int));
    return result;
}

void removeStolb(int**& arr, int& strk, int& stlb, int* indices, int count) {
    for (int k = 0; k < count; k++) {
        int delIndex = indices[k] - k;

        for (int i = 0; i < strk; i++) {
            for (int j = delIndex; j < stlb - 1; j++) {
                arr[i][j] = arr[i][j + 1];
            }
            arr[i] = (int*)realloc(arr[i], (stlb - 1) * sizeof(int));
        }

        stlb--;
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    int A, B, C, D;

    cout << "ПУНКТ 1\n\n";
    do {
        cout << "Введите A (неотрицательное) >> ";
        cin >> A;
        if (A < 0) cout << "A должно быть неотрицательным.\n";
    } while (A < 0);

    do {
        cout << "Введите B (неотрицательное) >> ";
        cin >> B;
        if (B < 0) cout << "B должно быть неотрицательным.\n";
    } while (B < 0);

    cout << "Введите C >> ";
    cin >> C;

    cout << "Введите D >> ";
    cin >> D;

    int strok = 2 + A;
    int stolb = 2 + B;

    int** arr = (int**)malloc(strok * sizeof(int*));

    for (int i = 0; i < strok; i++) {
        arr[i] = (int*)malloc(stolb * sizeof(int));
    }

    for (int i = 0; i < strok; i++) {
        for (int j = 0; j < stolb; j++) {

            if (i == 0 && j == 0) {
                arr[i][j] = A;
            }
            else if (i == 0 && j == 1) {
                arr[i][j] = B;
            }
            else if (i == 1 && j == 0) {
                arr[i][j] = C;
            }
            else if (i == 1 && j == 1) {
                arr[i][j] = D;
            }

            else {
                arr[i][j] = ((i - 1) * C) + ((j - 1) * D);
            }
        }
    }



    int zeroCount;
    int* zeroStolb = findZeroStolb(arr, strok, stolb, zeroCount);

    if (zeroCount > 0) {
        removeStolb(arr, strok, stolb, zeroStolb, zeroCount);
    }

    for (int i = 0; i < strok; i++) {
        for (int j = 0; j < stolb; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    free(zeroStolb);
    for (int i = 0; i < strok; i++) free(arr[i]);
    free(arr);


    cout << "\n\nПУНКТ 2\n\n";

    double a, b;

    cout << "Введите a >> ";
    cin >> a;
    cout << "Введите b >> ";
    cin >> b;

    double* pa = new double(a);
    double* pb = new double(b);
    *pa *= 3;

    double temp = *pa;
    *pa = *pb;
    *pb = temp;

    cout << "Значение a = " << *pa << ", значение b = " << *pb << endl;

    delete pa;
    delete pb;

    return 0;
}
