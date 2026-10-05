#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

#define NOMINMAX
#include <windows.h>

class JaggedArray {
private:
    std::vector<std::vector<std::string>> data;

public:
    JaggedArray() = default;

    // Чтение значений из txt файла
    bool loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) return false;

        data.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string word;
            std::vector<std::string> row;
            while (ss >> word) {
                row.push_back(word);
            }
            data.push_back(row);
        }
        return true;
    }

    // Переопределить обращение по индексам А[i][j]
    std::vector<std::string>& operator[](size_t index) {
        return data[index];
    }

    const std::vector<std::string>& operator[](size_t index) const {
        return data[index];
    }

    // метод удаления элемента из массива по двойному индексу delete(i, j) (вместо delete - remove)
    void remove(size_t i, size_t j) {
        if (i < data.size() && j < data[i].size()) {
            data[i].erase(data[i].begin() + j);
        }
    }

    // по значению delete(item) (вместо delete - remove)
    void remove(const std::string& item) {
        for (auto& row : data) {
            for (auto it = row.begin(); it != row.end(); ) {
                if (*it == item) {
                    it = row.erase(it);
                }
                else {
                    ++it;
                }
            }
        }
    }

    // Метод добавления элемента item в конец строки k
    void add_endline(size_t k, const std::string& item) {
        if (k < data.size()) {
            data[k].push_back(item);
        }
    }

    // Оператор -
    JaggedArray operator-(const JaggedArray& other) const {
        JaggedArray result = *this;
        size_t minRows = std::min(result.data.size(), other.data.size());

        for (size_t i = 0; i < minRows; ++i) {
            for (const auto& item : other.data[i]) {
                auto& row = result.data[i];
                for (auto it = row.begin(); it != row.end(); ) {
                    if (*it == item) {
                        it = row.erase(it);
                    }
                    else {
                        ++it;
                    }
                }
            }
        }
        return result;
    }

    // Оператор --
    JaggedArray& operator--() {
        for (auto& row : data) {
            for (auto& str : row) {
                std::string cleanStr = "";
                for (char c : str) {
                    if (!std::isdigit(static_cast<unsigned char>(c))) {
                        cleanStr += c;
                    }
                }
                str = cleanStr;
            }
        }
        return *this;
    }

    // Вывод массива
    void print() const {
        const std::string colors[] = {
            "\033[31m", // Красный
            "\033[32m", // Зеленый
            "\033[33m", // Желтый
            "\033[34m", // Синий
            "\033[35m", // Пурпурный
            "\033[36m"  // Голубой
        };
        const std::string reset = "\033[0m";

        for (size_t i = 0; i < data.size(); ++i) {
            std::cout << colors[i % 6];
            for (const auto& item : data[i]) {
                std::cout << item << " ";
            }
            std::cout << reset << "\n";
        }
    }

    // Сортировка
    void sortRows() {
        for (auto& row : data) {
            std::sort(row.begin(), row.end());
        }
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    JaggedArray A;
    A.loadFromFile("input.txt");

    std::cout << "Массив A:" << std::endl;
    A.print();

    std::cout << "\nЭлемент A[0][1]:" << std::endl;
    std::cout << A[0][1] << std::endl;

    std::cout << "\nДобавление элемента в конец строки 1:" << std::endl;
    A.add_endline(0, "orange");
    A.print();

    std::cout << "\nСортировка:" << std::endl;
    A.sortRows();
    A.print();

    return 0;
}
