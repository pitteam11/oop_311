#include <iostream>
#include <time.h>
#include <ctime>

using namespace std;

tm today() {
	tm today;
	today.tm_year = 2024;
	today.tm_mon = 6;
	today.tm_wday = 17;
	return today;
}

class Mark {
public:
	string lesson;
	tm	 date;
	int    value;
	
	Mark() {

	}

	Mark(string lesson, tm date, int value) :
		lesson{ lesson }, date{ date }, value{ value } {
	}

	// конструктор копирования
	Mark(const Mark &m) : Mark(m.lesson, m.date, m.value) {
	}

	Mark(int value): Mark("math", today(), value) {
	}

};

class Student {
private:
	const string name;
	Mark* marks = nullptr;
public:
	
	Student(string name) : name{name} {		
	}

	int num_mark = 0;

	// этот кусок не работает
	//int num_mark() const {
	//	if (marks) {
	//		return _msize(marks) / sizeof(marks[0]);
	//	}
	//	else {
	//		return 0;
	//	}
	//}

	Student(const Student& s) {
		int size = s.num_mark;
	
	// Этот вариант приводит к большому числу копирований
	//	for (int k = 0; k < size; k++)
	//		this->add_mark(s.marks[k]);

		marks = new Mark[size];
		for (int k = 0; k < size; k++)
			marks[k] = s.marks[k];
	}

	void add_mark(Mark& mark) {
		int size = num_mark;
		Mark* buff = new Mark[size + 1];
		for (int k = 0; k < size; k++)
			buff[k] = marks[k];
		buff[size] = mark;
		delete[] marks;
		marks = buff;
		num_mark++;
	}

	void show() {
		cout << name << endl;
		int size = num_mark;
		for (int k = 0; k < size; k++) {
			cout << marks[k].lesson << " ";
			cout << marks[k].date.tm_wday << " ";
			cout << marks[k].value << endl;
		}
	}

	~Student() {
		delete[] marks;
	}
};

void test_datetime() {
	// Что храниться в структуре tm
	tm date;
	date.tm_year = 2024;
	date.tm_mon = 1;
	date.tm_mday = 13;
}

void test_mark() {
	Mark mark1("life_safety", today(), 5);
	cout << mark1.lesson << " " << mark1.value << endl;

	Mark mark2(1);
	cout << mark2.value << endl;
	Mark mark3(mark1);
	cout << mark3.value << endl;
}

void test_student() {
	                                                                  
	string lessons[]{ "life_safety", "math", "phys", "art", "english", "literature" };

	Student student1("Petr Goncharov");
	for (int k = 0; k < 10; k++) {
		Mark mark1(lessons[rand() % 6], today(), rand() % 5 + 1);
		student1.add_mark(mark1);
	}
	student1.show();
}

int main() {
	srand(time(NULL));
	//test_mark();
	test_student();
	return 0;
}