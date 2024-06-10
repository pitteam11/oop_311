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
};

class Cat:public Animal {
};

class Dog :public Animal {
};

void walk(Animal any, int new_x=8, int new_y=8) {
	any.move(new_x, new_y);
	any.get_pos();
}


class Hardware {
private:
	int id = 0;
	string sn = "";
public:
	Hardware() {};
	Hardware(int id, string sn) : id{ id }, sn{sn} {};
	~Hardware() {};

	int get_id() {
		return id;
	}

	string get_sn() {
		return sn;
	}
};

class Mouse : public Hardware {
};

class Keyboard : public Hardware {
};

class Printer : public Hardware {
};



int main() {
	system("chcp 1251"); // вместо setlocale(LC_ALL, "ru")
	system("cls");
	//system("pause");
	//system("git add .")

	cout << "Привет" << endl;

	Animal chudo_yuda;
	chudo_yuda.move(4,7);
	chudo_yuda.get_pos();

	Cat Musya;

	Musya.move(6, 3);
	Musya.get_pos();

	Dog Bobik;

	walk(Musya, 1, 1);

	walk(Bobik, 2, 5);

	return 0;
}