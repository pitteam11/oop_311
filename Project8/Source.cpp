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

	inline void set_n(const int n) {
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
	Number& operator+(const Number& b) const {
		auto res = Number(n + b.n);
		return res;
	}

	Number& operator*(const Number& b) const {
		auto res = Number(n * b.n);
		return res;
	}

	Number& operator-(const Number& b) const {
		auto res = Number(b.n - n);
		return res;
	}

	Number& operator/(const Number& b) const {
		auto res = Number(b.n / n);
		return res;
	}

	Number& operator%(const Number& b) const {
		auto res = Number(n%b.n);
		return res;
	}


	// logical
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

};

void test1() {
	Number a(123);
	Number b(7);
	Number c = a + b;
	cout << a << " + " << b << " = " << c << endl;
}

int main() {
	test1();
	return 0;
}