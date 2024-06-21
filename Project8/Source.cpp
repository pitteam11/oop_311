#include <iostream>

using namespace std;

class Number {
private:
	int n;

public:
	explicit Number(const int n=0) : n{ n } {
	}

	inline int get_n() const{
		return n;
	}

	inline void set_n(const int n=0) {
		this->n = n;
	}

	friend ostream& operator<<(ostream& out, const Number& obj) {
		out << obj.n;
		return out;
	}

	friend istream& operator>>(istream& in, Number& obj) {
		in >> obj.n;
		return in;
	}

	// arithmetical
	Number operator+(const Number& obj) const {
		auto res = Number(n + obj.n);
		return res;
	}

	Number operator*(const Number& obj) const {
		auto res = Number(n * obj.n);
		return res;
	}

	Number operator-(const Number& obj) const {
		auto res = Number(n - obj.n);
		return res;
	}

	Number operator/(const Number& obj) const {
		auto res = Number(n / obj.n);
		return res;
	}

	Number operator%(const Number& obj) const {
		auto res = Number(n % obj.n);
		return res;
	}

	// logical - like operator C++20 <=> "spaceship"
	bool operator==(const Number& b) const {		
		return n == b.n;
	}

	bool operator>=(const Number& b) const {
		return n >= b.n;
	}

	bool operator>(const Number& b) const {
		return n > b.n;
	}

	bool operator<(const Number& b) const {
		return n < b.n;
	}

	bool operator<=(const Number& b) const {
		return n <= b.n;
	}

	bool operator!=(const Number& b) const {
		return n != b.n;
	}

	// copy constructor (перегрузка не нужна)
	Number(const Number& obj) {
		n = obj.n;		
	}

	// Запретить автоматическое создание оператора копирования
	//Number operator=(const Number& obj) = delete;

	// Заставить создать по-умолчанию оператор копирования
	//Number operator=(const Number& obj) = default;
	
	// appropriation - copy operator (перегрузка не нужна)
	Number operator=(const Number& obj) {
		auto res = Number(obj.n);
		return res;
	}
};

class Empty {

public:
	//~Empty() = delete;
};

void test1() {
	Number a(123);
	//a.set_n(512);
	int r = a.get_n();
	cout << ++r << endl;

	Number b(7);
	Number c = a + b;
	Number d(8);	
	Number rr = a;
	Number z;
	z = b;

	cout << a << " + " << b << " = " << c << endl;
	cout << a << " - " << b << " = " << a-b << endl;
	cout << a << " / " << b << " = " << a/b << endl;
	cout << a << " % " << b << " = " << a%b << endl;
	cout << a + b + d << endl;
}

int main() {

	Empty r();


	//test1();
	return 0;
}