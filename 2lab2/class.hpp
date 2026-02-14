#pragma once

#include <iostream>
#include <string>
#include <vector>

class Student {
public:
    Student();
    Student(const Student& other);

    Student(const std::string& name, const std::string& surname, const std::vector<std::string>& debts);

    ~Student();

    Student& operator=(const Student& other);
    Student operator+(const Student& other) const ;
    Student& operator-=(const Student& other);
    Student operator/(const Student& other) const;

    void print_full();

    std::string get_name() const;
    std::string get_surname() const;
    std::string get_debts() const;

private:
    std::string name_;
    std::string surname_;
    std::vector<std::string> debts_;
};