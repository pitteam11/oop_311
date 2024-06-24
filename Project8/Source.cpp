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
	Number& operator=(const Number& obj) {
		auto res = Number(obj.n);
		return res;
	}

	Number& operator=(Number&& obj) {
		auto res = Number(obj.n);
		return res;
	}

	

	Number add(int val) {
		n += val;
		return *this;
	}

	Number mult(int val) {
		n *= val;
		return *this;
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

	Number new_a = a.add(15).mult(2).add(-5);
	z = new_a; // тут не работает
	cout << z << endl;
}

void test_reference() {
	int very_long_name_for_variables = 17;
	int x = very_long_name_for_variables;
	// l-value reference
	int& y = very_long_name_for_variables;
	y = 2;
	cout << very_long_name_for_variables << endl;

	int&& rval = 4 + 17;	
	cout << rval << endl;
}

class DynArray {
private:
	int* data;
	int size = 0;

public:
	DynArray(int size, int* data) : size{size} {
		// deep copy
		this->data = new int[size];
		for (int k = 0; k < size; k++)
			this->data[k] = data[k];
	}

	// copy constructor
	DynArray(const DynArray& a) : size{a.size} {
		// deep copy
		if (this != &a) {
			this->data = new int[size];
			for (int k = 0; k < size; k++)
				this->data[k] = a.data[k];
		}
	}

	// move constructor
	DynArray(DynArray&& a) : size{ a.size } {
		if (this != &a) {
			// deep copy
			if (data) delete[] data;
			data = a.data;
			a.data = nullptr;
			a.size = 0;
		}
	}

	~DynArray() {
		delete[] data;
	}

	// copy operator
	DynArray operator=(const DynArray& a)  {
		if (this != &a) {
			size = a.size;
			if (data) delete[] data;
			data = new int[size];
			for (int k = 0; k < size; k++)
				this->data[k] = a.data[k];
			return *this;
		}
	}

	// move operator
	DynArray operator=(DynArray&& a) {
		if (this != &a) {
			size = a.size;
			if (data) delete[] data;
			data = a.data;
			a.data = nullptr;
			a.size = 0;
			return *this;
		}
	}

	void show() const {
		for (int k = 0; k < size; k++)
			cout << data[k] << " ";
		cout << endl;
	}

	void set_data(int k, int val) {
		data[k] = val;
	}
};

void test_dynarray() {
	int* data = new int[] {1, 2, 3, 4, 5, 6};
	DynArray arr(6, data);
	arr.show();
	data[1] = 100;
	arr.show();
	
	int* temp = new int[6]{};
	DynArray arr2(6, temp);
	arr2 = arr;
	arr.set_data(1, 200);
	cout << "arr: ";
	arr.show();
	cout << "arr2: ";
	arr2.show();

	arr2 = DynArray(6, data);
	arr2.show();


	delete[] data;
	delete[] temp;
}


int main() {
	test_dynarray();
	//test_reference();
	//Empty r();
	//test1();
	return 0;
}