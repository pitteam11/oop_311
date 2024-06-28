#include <iostream>

using namespace std;



int get_anysum(int count, int first, int ...) {
	int* pfirst = &first;
	int res = 0;
	while (count > 0) {
		res += *pfirst;
		// Attention double step
		pfirst+=2;
		--count;
	}
	return res;
}

int get_sum(int a=0, int b=0, int c=0) {

	cout << &a << " ";
	cout << &b << " ";
	cout << &c << " ";
	cout << endl;

	int* pa = &a;
	cout << *pa << " " << *(pa + 1) << " " << *(pa + 2) << endl;

	return a + b + c;
}

class Animal {
protected:
	string name;
public:

	
	Animal(string name) : name{ name } {};

	void set_name(const string& name) {
		this->name = name;
	}
	// abstarct
	//virtual void say();
	virtual void say() {
		cout << name << " " << "RRRR" << endl;
	}
};

class Cat : public Animal {
public:
	Cat(string name) : Animal(name) {};

	virtual void say() override	{
		cout << name << " " << "Myau Myau" << endl;
	}
};

class Dog : public Animal {
public:
	Dog(string name) : Animal(name) {};

	virtual void say() override {
		cout << name << " " << "Gav Gav" << endl;
	}
};

void test1(int argc, char* argv[]) {
	cout << argv[0] << endl;
	if (argc == 1) {
		cout << "get_sum(1): " << get_sum(1) << endl;
		cout << "get_sum(1, 2): " << get_sum(1, 2) << endl;
		cout << "get_sum(1, 2, 3): " << get_sum(1, 2, 3) << endl;

		cout << get_anysum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
	}
	else if (argc == 2) {
		if (!strcmp(argv[1], "--help")) {
			cout << "This is test project. Don't afraid" << endl;
		}
		else if (!strcmp(argv[1], "--version")) {
			cout << "Project10 1.0.0" << endl;
		}

	}
}

//void walk(Cat& cat) {
//	cat.say();
//}

void walk(Animal& animal) {
	animal.say();
}

void test_animals() {
	Animal animal1("John Do");
	//animal1.set_name("John Do");
	animal1.say();

	Cat cat1("Musya");
	//cat1.set_name("Musya");
	cat1.say();

	Dog dog1("Sharik");
	dog1.say();

	Animal* animals[]{ &cat1, &dog1, &animal1 };

	for (int k = 0; k < 3; ++k)
		animals[k]->say();

	walk(cat1);
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	test_animals();
	return 0;
}