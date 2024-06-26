#include <iostream>

using namespace std;

template <class T>
class Point {
private:
	T x;
	T y;
	T z;

public:
	Point() = default;
	Point(T x, T y, T z) : x{ x }, y{ y }, z{ z }{};

	double distance(const Point& p) const {
		T dx = x - p.x;
		T dy = y - p.y;
		T dz = z - p.z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}
};


int main() {
	Point<int> p1(1, 2, 3);
	Point<int> p2(2, 3, 1);
	cout << p1.distance(p2) << endl;

	Point<double> p3(0.5, 2.1, 3.3);
	Point<double> p4(2.1, 3.5, 1.7);
	cout << p3.distance(p4) << endl;

	return 0;
}