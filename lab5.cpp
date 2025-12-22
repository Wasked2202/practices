#include <iostream>
#include <locale.h>
#include <float.h>
#include <vector>
using namespace std;


int punkt, a, b, c;

int rule(int a, int b) {
	if (a % b == 0) {
		return a / b;
	}
	if (b % a == 0) {
		return b / a;
	}
	else {
		return a * b;
	}
}
int rule(int a, int b, int c) {
	cout << "Исполняется функция работы с тремя числами" << endl;
	if (a == b && a == c) {
		return 1;
	}
	else {
		return -1;
	}
}

void p1() {
	int arr[3];

	for (int i = 0; i < 3; ++i) {
		cin >> arr[i];
	}

	if (arr[0] != 0 && arr[1] != 0 && arr[2] != 0) {
		a = arr[0];
		b = arr[1];
		c = arr[2];
		cout << rule(a, b, c);
	}

	if (arr[0] == 0 && arr[1] != 0 && arr[2] != 0) {
		a = arr[1];
		b = arr[2];
		cout << rule(a, b);
	}
	if (arr[0] != 0 && arr[1] == 0 && arr[2] != 0) {
		a = arr[0];
		b = arr[2];
		cout << rule(a, b);
	}
	if (arr[0] != 0 && arr[1] != 0 && arr[2] == 0) {
		a = arr[0];
		b = arr[1];
		cout << rule(a, b);
	}


}

void p2() {
	int sum, raznab, raznba, proizv, sizeflt, sizeint, minint, maxint;
	float fa, fb, delab, delba, minflt, maxflt;


	sum = a + b;
	raznab = a - b;
	raznba = b - a;
	proizv = a * b;
	fa = a;
	fb = b;
	delab = fa / fb;
	delba = fb / fa;
	sizeflt = sizeof(float);
	sizeint = sizeof(int);

	cout << "\nСумма: " << sum << endl;
	cout << "Разность a-b: " << raznab << endl;
	cout << "Разность b-a: " << raznba << endl;
	cout << "Произведение: " << proizv << endl;
	cout << "Деление a/b: " << delab << endl;
	cout << "Деление b/a: " << delba << endl;

	minflt = FLT_MIN;
	maxflt = FLT_MAX;
	minint = INT_MIN;
	maxint = INT_MAX;

	cout << "\nТип данных - int, " << sizeint << " байта, или " << sizeint * 8 << " бита (Минимальное значение : " << minint << ", максимальное : " << maxint << endl;
	cout << "Тип данных - float, " << sizeflt << " байта, или " << sizeflt * 8 << " бита (Минимальное значение : " << minflt << ", максимальное : " << maxflt << endl;
}


int main() {
	setlocale(LC_ALL, "RU");

	cin >> punkt;

	if (punkt == 1) {
		p1();
	}

	if (punkt == 2) {
		cout << "Введите первое неотрицательное число >> ";
		cin >> a;
		cout << "Введите второе неотрицательное число >> ";
		cin >> b;
		p2();
	}

}