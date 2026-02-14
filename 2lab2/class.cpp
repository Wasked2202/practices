#include "class.hpp"

// Конструктор по умолчанию
Student::Student() : name_(""), surname_(""), debts_({}) {}

// Конструктор копирования
Student::Student(const Student& other)
    : name_(other.name_),
      surname_(other.surname_),
      debts_(other.debts_) {
    std::cout << "copy ctor" << std::endl;
}

// Конструктор полного заполнения
Student::Student(const std::string& name,
                 const std::string& surname,
                const std::vector<std::string>& debts)
    : name_(name),
      surname_(surname), 
      debts_(debts) {
    std::cout << "fill ctor" << std::endl;
}

Student::~Student() {
    debts_.clear();
    std::cout << "dtor" << std::endl;
}

Student& Student::operator=(const Student& other) {
    Student tmp = other;
    std::swap(tmp.name_, name_);
    std::swap(tmp.surname_, surname_);
    std::swap(tmp.debts_, debts_);
    return *this;
}

Student Student::operator+(const Student& other) const {
    Student summ;

    summ.name_ = name_ + " и " + other.name_;
    summ.surname_ = surname_ + " и " + other.surname_;
    summ.debts_ = debts_;
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

    std::vector<std::string> minus;

    for (int i = 0; i < debts_.size(); i++) {
        const std::string& debt = debts_[i];

        if (std::find(other.debts_.begin(), other.debts_.end(), debt) == other.debts_.end()) {
            minus.push_back(debt);
        }
    }

    debts_ = minus;
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