#include <iostream>

class Student {
public:
	// Конструктор по умолчанию 
	Student() : name_(""), surname_(""), direction_(""),
		course_(1), group_(1), var_(1) {}

	// Конструктор копирования
	Student(const Student& other) : name_(other.name_), surname_(other.surname_),
		direction_(other.direction_), course_(other.course_),
		group_(other.group_), var_(other.var_) {
		std::cout << "copy ctor" << std::endl;
	}

	// Конструктор полного заполнения
	Student(const std::string& name, const std::string& surname,
		const std::string& direction, const int& course, const int& group, const int& var) : name_(name), surname_(surname), direction_(direction),
		course_(course), group_(group), var_(var) {
		std::cout << "fill ctor" << std::endl;
	}

	~Student() {
		std::cout << "dtor" << std::endl;
	}

	void set_var(int var) {
		var_ = var;
	}
	void set_course(int course) {
		course_ = course;
	}

	void print_full() {
		std::cout << "Имя: " << name_ <<
			"\nФамилия: " << surname_ <<
			"\nНаправление: " << direction_ <<
			"\nКурс: " << course_ <<
			"\nГруппа: " << group_ <<
			"\nВариант: " << var_ << std::endl;
	}

	void next_course() {
		course_++;
	}

	std::string get_name() const { return name_; }
	std::string get_surname() const { return surname_; }
	std::string get_direction() const { return direction_; }
	int get_course() const { return course_; }
	int get_group() const { return group_; }
	int get_var() const { return var_; }

private:
	std::string name_;
	std::string surname_;
	std::string direction_;
	int course_;
	int group_;
	int var_;
};


int main() {
	setlocale(LC_ALL, "Russian");

	Student stud1();
	Student stud2("Анна", "Петрова", "Математическое обеспечение", 1, 2, 6);
	Student stud3(stud2);

	stud2.print_full();

	stud3.set_course(2);
	stud3.set_var(12);
	stud3.next_course();

	std::cout << stud3.get_name() << ", " << stud3.get_surname() << ", " << stud3.get_direction() << ", " << stud3.get_course() << ", " << stud3.get_group() << ", " << stud3.get_var() << std::endl;

	return 0;
}
