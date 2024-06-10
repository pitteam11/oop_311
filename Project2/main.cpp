#include <iostream>

using namespace std;

class Animal {
private:
	int x = 0;
	int y = 0;

public:
	void move(int new_x, int new_y) {
		x = new_x;
		y = new_y;
	}

	void get_pos() {
		cout << x << ", " << y << endl;
	}

	void sound() {
		cout << "RRRRR" << endl;
	}
};

class Cat:public Animal {
public:
	void sound() {
		cout << "Myau Myau" << endl;
	}
};

class Dog :public Animal {
public:
	void sound() {
		cout << "Gav Gav" << endl;
	}
};

void walk(Animal any, int new_x=8, int new_y=8) {
	any.move(new_x, new_y);
	any.sound();
	any.get_pos();
}


class Hardware {
private:
	int id = 0;
	string sn = "";
public:
	//Hardware() {};
	Hardware(int id, string sn) : id{ id }, sn{sn} {};
	~Hardware() {};

	int get_id() {
		return id;
	}

	string get_sn() {
		return sn;
	}
};

// ����� ����� ������������ ������ � �����������.
class Mouse : public Hardware {
public:
	Mouse(int id, string sn) : Hardware(id, sn) {};
};

class Keyboard : public Hardware {
public:
	Keyboard(int id, string sn) : Hardware(id, sn) {};
};

class Printer : public Hardware {
public:
	Printer(int id, string sn) : Hardware(id, sn) {};
};

void test_animal() {
	Animal chudo_yuda;
	chudo_yuda.move(4, 7);
	chudo_yuda.get_pos();

	Cat Musya;

	Musya.move(6, 3);
	Musya.get_pos();

	Dog Bobik;

	walk(Musya, 1, 1);
	walk(Bobik, 2, 5);

	chudo_yuda.sound();
	Bobik.sound();
	Musya.sound();

	Dog* pSharik{};
	pSharik->sound();

	Animal* animals[2];
	
	animals[0] = pSharik;
	animals[1] = &Musya;

	// ����������� ��������� �� ���������.
	cout << "Sharik ";
	((Cat*)animals[0])->sound();
	cout << "Musya ";
	((Dog*)animals[1])->sound();
}

void test_hardware() {
	Mouse device1(45, "MOUSE-12"); // �� �������� ����������� ��� ����������
	cout << device1.get_id() << " " 
		 << device1.get_sn() << endl;
	
}

int main() {
	system("chcp 1251"); // ������ setlocale(LC_ALL, "ru")
	system("cls");
	//system("pause");
	//system("git add .")


	cout << "������" << endl;
	//test_animal();

	test_hardware();

	return 0;
}