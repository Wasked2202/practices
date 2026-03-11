#pragma once

#include <iostream>
#include <string>
#include <vector>

struct Statement {
    std::string name_;
    std::string surname_;
    std::string type_;
    std::string comment_;
    int data_;
};

class Student {
private:
    std::string name_;
    std::string surname_;
	std::string direction_;
	int course_;
	int group_;
	int var_;
    std::vector<std::string> debts_;

public:
    Student();
    Student(const Student& other);
    Student(const std::string& name, const std::string& surname, const std::string& direction_, const int& course_, const int& group_, const int& var_, const std::vector<std::string>& debts);
    ~Student();

    Student& operator=(const Student& other);
    Student operator+(const Student& other) const ;
    Student& operator-=(const Student& other);
    Student operator/(const Student& other) const;

    void print_full();

    std::string get_name() const;
    std::string get_surname() const;
    std::string get_direction() const;
    int get_course() const;
    int get_group() const;
    int get_var() const;
    std::string get_debts() const;

    void set_name(std::string name);
    void set_surname(std::string surname);
    void set_direction(std::string direction);
    void set_course(int course);
    void set_group(int group);
    void set_var(int var);
    void set_debts(std::vector<std::string> debts);

    Statement next_course(std::string comment);
    Statement other_group(std::string comment, int newGroupNum);
};

class Dekanat {
    private:
        std::string address_;
        std::vector<Student*> students_;
    public:
        Dekanat(const std::string& address);
        ~Dekanat();
        Dekanat(const Dekanat&) = delete;

        void assign(Student* s);
        void expulsion(Student* s);
};
