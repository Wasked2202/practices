#include <iostream>
#include <windows.h>
#include <vector>
#include <locale.h>
#include <string>
#include <iomanip>

struct tovar {
	std::string name;
	std::string prod;
	std::vector<std::string> sost;
	int weight;
	float price;
};

void printCatalog(const std::vector<tovar>& catalog) {
	std::cout << "Каталог товаров:" << std::endl;
	for (int i = 0; i < catalog.size(); i++) {
		const tovar& t = catalog[i];
		std::string sostString;

		for (int s = 0; s < t.sost.size(); s++) {
			sostString += t.sost[s];
			if (s + 1 < t.sost.size()) {
				sostString += " + ";
			}
		}

		std::cout << t.prod << ", " << t.name << ", " << sostString << ", " << t.weight << "гр, " << std::fixed << std::setprecision(2) << t.price << "руб." << std::endl;
	}
	std::cout << "\n";
}

void editTovar(std::vector<tovar>& catalog) {
	int editmenu;

	do {
		for (int i = 0; i < catalog.size(); i++) {
			const tovar& t = catalog[i];
			std::cout << i + 1 << ". " <<  t.name << " " << t.weight << "гр" << std::endl;
		}

		std::cout << "90. Назад\n99. Выход из программы\nВведите номер: ";
		std::cin >> editmenu;
		std::cin.ignore();
		std::cout << "\n";

		if ((editmenu > 0) and (editmenu <= catalog.size())) {
			tovar& t = catalog[editmenu - 1];
			int punkt;
			std::cout << "1. Название\n2. Производитель\n3. Состав\n4. Вес\n5. Цена\n90. Назад\n99. Выход из программы\nВведите номер: ";
			std::cin >> punkt;
			std::cin.ignore();
			std::cout << "\n";

			switch (punkt) {
				case 1:
					do {
						std::cout << "Название: ";
						std::getline(std::cin, t.name);
						if (t.name.length() > 15) { std::cout << "Ошибка: название должно быть не более 15 символов!" << std::endl; }
					} while (t.name.length() > 15);
					std::cout << "\n";
					break;
				case 2:
					std::cout << "Производитель: ";
					std::getline(std::cin, t.prod);
					std::cout << "\n";
					break;
				case 3: {
					std::cout << "Добавить новый элемент состава (пустой ввод = удалить последний элемент): ";
					std::string element;
					std::getline(std::cin, element);

					if (element.empty()) {
						if (!t.sost.empty()) { t.sost.pop_back(); }
						else { std::cout << "\nНечего удалять, состав пуст..."; }
					}
					else {
						t.sost.push_back(element);
					}
					std::cout << "\n";
					break;
				}
				case 4:
					do {
						std::cout << "Вес: ";
						std::cin >> t.weight;
						if (t.weight > 1000000) { std::cout << "Ошибка: вес должен быть не более тонны!" << std::endl; }
						if (t.weight <= 0) { std::cout << "Ошибка: вес должен быть более 0 грамм!" << std::endl; }
					} while ((t.weight > 1000000) or (t.weight <= 0));
					std::cout << "\n";
					break;
				case 5:
					std::cout << "Цена: ";
					std::cin >> t.price;
					std::cin.ignore();
					std::cout << "\n";
					break;
				case 90:
					break;
				case 99:
					editmenu = 99;
					break;
				default:
					std::cout << "Такой номер выбрать нельзя!\n";
					break;
			}
		}

	} while ((editmenu != 90) and (editmenu != 99));

	if (editmenu == 99) {
		exit(0);
	}
}

void addTovar(std::vector<tovar>& catalog) {
	tovar t;

	do {
		std::cout << "Название: ";
		std::getline(std::cin, t.name);
		if (t.name.length() > 15) {std::cout << "Ошибка: название должно быть не более 15 символов!" << std::endl;}
	} while (t.name.length() > 15);

	std::cout << "Производитель: ";
	std::getline(std::cin, t.prod);

	while (true) {
		std::cout << "Элемент состава (пустой ввод = конец): ";
		std::string element;
		std::getline(std::cin, element);

		if (element.empty()) break;
		t.sost.push_back(element);
	}

	do {
		std::cout << "Вес: ";
		std::cin >> t.weight;
		if (t.weight > 1000000) {std::cout << "Ошибка: вес должен быть не более тонны!" << std::endl;}
		if (t.weight <= 0) {std::cout << "Ошибка: вес должен быть более 0 грамм!" << std::endl;}
	} while ((t.weight > 1000000) or (t.weight <= 0));

	std::cout << "Цена: ";
	std::cin >> t.price;

	std::cin.ignore();
	std::cout << "\n";
	catalog.push_back(t);

}

int main(){
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu;
	
	std::vector<tovar> catalog{
		{ "Майонез \"Деревенька\"", "ИП Соловьев", {"яичный желток", "вода", "масло", "соль"}, 250, 105.60 },
		{ "Сахар \"Сладкий\"", "ИП Пирогов", {"сахар песок", "подсластители"}, 1000, 105.60 },
		{ "Вода \"Источник\"", "ИП Сточинский", {"вода"}, 150, 40.30 },
		{ "Колбаса \"Докторская\"", "ООО Мясничок", {"свинина", "говядина", "специи"}, 500, 450.80 },
		{ "Хлеб \"Бородинский\"", "ИП Островский", {"мука", "дрожжи", "вода"}, 550, 65.50}

	};

	do {
		std::cout << "Выберите действие:\n1. Просмотр товаров\n2. Редактирование товаров\n3. Добавление товаров\n99. Выход из программы\nВведите номер: ";
		std::cin >> menu;
		std::cin.ignore();
		std::cout << "\n";

		switch(menu){
			case 1:
				printCatalog(catalog);
				break;
			case 2:
				editTovar(catalog);
				break;
			case 3:
				addTovar(catalog);
				break;
		}
	} while (menu != 99);
}