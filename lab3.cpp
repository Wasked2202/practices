#include <iostream>
using namespace std;

int i, n, x, proizv;
float num, sum, maxim, maxn;

int main()
{
    setlocale(LC_ALL, "Russian");

    // Пункт 1

    cout << "ПУНКТ 1\nСколько чисел в последовательности? >> ";
    cin >> i;
    n = 1;
    sum = 0;
    maxim = -0.36;
    maxn = 0;
    for (i; i > 0; i--) {
        cout << "Введите A" << n << " >> ";
        cin >> num;
        if ((num > -0.36) && (num <= 10.1)) {
            sum += num;
            if (maxim < num) {
                maxim = num;
                maxn = n;
            }
        }
        n++;
    }
    if (maxn == 0) {
        cout << "Подходящих чисел в последовательности найдено не было." << endl;
    }
    else {
        cout << "Сумма: " << sum << "\nНаибольшее: " << maxim << "\nНомер наибольшего в последовательности: " << maxn << endl;
    }
    // Пункт 2

    cout << "\nПУНКТ 2\nВведите число x >> ";
    cin >> x;
    x = abs(x);
    proizv = 1;
    if (x > 1000) {
        cout << "Некорректный ввод!";
    }
    else {
        do {
            proizv = proizv * (x % 10);
            x /= 10;
        } while (x > 0);
        cout << "Произведение всех цифр этого числа: " << proizv;
    }

    return 0;
}
