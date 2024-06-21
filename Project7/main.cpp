#include <iostream>

using namespace std;

class Fraction {
private:
	int Num;
	int Den;
public:
	Fraction(int Num, int Den) : Num{ Num }, Den{Den} {
	}

	void show() const {
		cout << Num << "/" << Den;
	}

	// no modified method
	Fraction add(const Fraction& b) const {
		int n = Num * b.Den + b.Num * Den;
		int d = Den * b.Den;
		return Fraction(n, d);
	}

	Fraction operator*(const Fraction& b) const {
		int n = Num * b.Num;
		int d = Den * b.Den;
		return Fraction(n, d);
	}

	Fraction operator+(const Fraction& b) const {
		int n = Num * b.Den + b.Num * Den;
		int d = Den * b.Den;
		return Fraction(n, d);
	}

	friend ostream& operator<<(ostream& output, const Fraction& a){		
		output << "I'm operator<<" << a.Num << "/" << a.Den;
		return output;
	}

	friend istream& operator>>(istream& input, Fraction& a) {
		input >> a.Num >> a.Den;
		return input;
	}


	friend void show_frind(const Fraction& a) {
		cout << "I'm friend: ";
		cout << a.Num << "/" << a.Den;
	}
};

// global function
void glob_show(Fraction& a) {
	cout << "Fraction: ";
	a.show(); // execute inner method
	// cout << a.Den; // Den private!!!!
}

int main() {
	const Fraction a(2, 5); // 2/5 
	const Fraction b(1, 3); // 1/3
	
	// inner method
	a.show();

	//
	show_frind(a);


	Fraction c = a + b;
	cout << endl;
						
	//const Fraction c = a.add(b);
	a.show();
	cout << " + ";
	b.show();
	cout << " = ";
	c.show();
	cout << endl;


	Fraction e = a * b;

	//const Fraction c = a.add(b);
	a.show();
	cout << " * ";
	b.show();
	cout << " = ";
	e.show();
	cout << endl;

	cout << a;

	//cout << a << " * " << b << " = " << e << endl;
	
	return 0;
}