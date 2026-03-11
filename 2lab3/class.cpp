#include "class.hpp"

// Конструктор по умолчанию
Student::Student() : name_(""), surname_(""), direction_(""), course_(), group_(), var_(), debts_({}) {}

// Конструктор копирования
Student::Student(const Student& other)
    : name_(other.name_),
      surname_(other.surname_),
      direction_(other.direction_),
      course_(other.course_),
      group_(other.group_),
      var_(other.var_),
      debts_(other.debts_) {
}



Student::~Student() {
    debts_.clear();
}

Student& Student::operator=(const Student& other) {
    Student tmp = other;
    std::swap(tmp.name_, name_);
    std::swap(tmp.surname_, surname_);
    std::swap(tmp.debts_, debts_);
    if (this == &other) return *this;
    return *this;
}

Student Student::operator+(const Student& other) const {
    Student summ;

    summ.name_ = name_ + " и " + other.name_;
    summ.surname_ = surname_ + " и " + other.surname_;
    for (int i = 0; i < debts_.size(); i++) {
        const std::string& debt = debts_[i];

        if (std::find(summ.debts_.begin(), summ.debts_.end(), debt) == summ.debts_.end()) {
            summ.debts_.push_back(debt);
        }
    }
    for (int i = 0; i < other.debts_.size(); i++) {
        const std::string& debt = other.debts_[i];

        if (std::find(summ.debts_.begin(), summ.debts_.end(), debt) == summ.debts_.end()) {
            summ.debts_.push_back(debt);
        }
    }
    
    return summ;
}

Student& Student::operator-=(const Student& other) {
    name_ = name_ + " без " + other.name_;
    surname_ = surname_ + " без " + other.surname_;

    for (auto it = debts_.begin(); it != debts_.end();) {
        if (std::find(other.debts_.begin(), other.debts_.end(), *it) != other.debts_.end()) {
            it = debts_.erase(it);
        } else {
            ++it;
        }
    }

    return *this;
}

Student Student::operator/(const Student& other) const {
    Student division;

    division.name_ = name_ + " и " + other.name_;
    division.surname_ = surname_ + " и " + other.surname_;

    for (int i = 0; i < debts_.size(); i++) {
        const std::string& debt = debts_[i];

        if (std::find(other.debts_.begin(), other.debts_.end(), debt) != other.debts_.end()) {
            division.debts_.push_back(debt);
        }
    }

    return division;
}


void Student::print_full() {
    std::string debtlist = "";
    for (int i = 0; i < debts_.size(); i++) {
			debtlist += debts_[i];
			if (i + 1 < debts_.size()) {
				debtlist += ", ";
			}
		}
    std::cout << "Имя: " << name_
              << "\nФамилия: " << surname_
              << "\nДолги: " << debtlist
              << std::endl;
}


std::string Student::get_name() const { return name_; }
std::string Student::get_surname() const { return surname_; }
std::string Student::get_direction() const { return direction_; }
int Student::get_course() const { return course_; }
int Student::get_group() const { return group_; }
int Student::get_var() const { return var_; }
std::string Student::get_debts() const { 
    std::string debtlist;
    for (int i = 0; i < debts_.size(); i++) {
			debtlist += debts_[i];
			if (i + 1 < debts_.size()) {
				debtlist += ", ";
			}
		}
    return debtlist;
}

void Student::set_name(std::string name) { name_ = name; }
void Student::set_surname(std::string surname) { surname_ = surname; }
void Student::set_direction(std::string direction) { direction_ = direction; }
void Student::set_course(int course) { course_ = course; }
void Student::set_group(int group) { group_ = group; }
void Student::set_var(int var) { var_ = var; }
void Student::set_debts(std::vector<std::string> debts) { debts_ = debts; }

Statement Student::next_course(std::string comment) {
	Statement statement;

    statement.name_ = name_;
    statement.surname_ = surname_;
    statement.type_ = "перевод_на_следующий_курс";
    statement.comment_ = comment;
    statement.data_ = course_ + 1;
    
    return statement;
}

Statement Student::other_group(std::string comment, int newGroupNum) {
	Statement statement;

    statement.name_ = name_;
    statement.surname_ = surname_;
    statement.type_ = "перевод_в_другую_группу";
    statement.comment_ = comment;
    statement.data_ = newGroupNum; 
    
    return statement;
}



Dekanat::Dekanat(const std::string& address) : address_(address), students_({}) {}

Dekanat::~Dekanat() {
    students_.clear();
}


void Dekanat::assign(Student* s) {
    auto it = std::find(students_.begin(), students_.end(), s);

    if (it == students_.end()) {
        students_.push_back(s);
        std::cout << "Студент успешно прикреплен к деканату по адресу: " << address_ << std::endl; }

    else {
        std::cout << "Студент уже прикреплён к этому деканату" << std::endl;
    }
}

void Dekanat::expulsion(Student* s) {
    auto it = std::find(students_.begin(), students_.end(), s);

    if (it != students_.end()) {
        students_.erase(it);
        std::cout << "Студент исключен из деканата по адресу " << address_ << std::endl; }
    else {
        std::cout << "Студент не найден в списке деканата по адресу " << address_ << std::endl;
    }
}


Student::Student(const std::string& name, 
                 const std::string& surname, 
                 const std::string& direction, 
                 const int& course, 
                 const int& group, 
                 const int& var, 
                 const std::vector<std::string>& debts)
    : name_(name), 
      surname_(surname), 
      direction_(direction), 
      course_(course), 
      group_(group), 
      var_(var), 
      debts_(debts) 
{ }
