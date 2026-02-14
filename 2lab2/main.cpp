#include <iostream>
#include <windows.h>
#include "class.hpp"

int main() {
	SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
	
  Student a("Андрей", "Петров", { "Информатика", "Геометрия", "Алгебра", "История" });
	Student b("Сергей", "Иванов", { "Геометрия", "История", "Математический анализ" });
	a.print_full();

	Student c = a + b;
	c -= b;
	Student d = a / b;

	b.get_debts();
	Student f = a;

	return 0;
}
