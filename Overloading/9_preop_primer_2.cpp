#include <iostream>
using namespace std;

class point {
public: // place public members first
	void print() const { cout << "(" << x << "," << y << ")"; }
	void set(double u, double v) { x = u; y = v; }
	void plus(point c);
	point inverse() { x = -x; y = -y; return (*this); }
	point* where_am_I() { return this; }
private:
	double x, y;
};

void point::plus(point c) { x += c.x; y += c.y; }
int main() {
	point a, b;
	a.set(1.5, -2.5);
	a.print();
	cout << "\na is at " << a.where_am_I() << endl;
	b = a.inverse();
	b.print();
	cout << "\nb is at " << b.where_am_I() << endl;
}
