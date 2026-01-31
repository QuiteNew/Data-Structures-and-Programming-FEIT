#include <iostream>
using namespace std;

class Rational {
public:
	Rational(int n = 0, int d = 1) : num(n), den(d) { }
	Rational(const Rational& r) : num(r.num), den(r.den) {}
	Rational& operator=(const Rational&);
	Rational& operator*=(const Rational&);
	bool operator==(const Rational&);
	void Show() const { cout << num << '/' << den << endl; }
private:
	int num, den;
};

Rational& Rational::operator=(const Rational& r) {
	num = r.num; den = r.den; return *this;
}

Rational& Rational::operator*=(const Rational& r) {
	num *= r.num; den *= r.den; return *this;
}

bool Rational::operator==(const Rational &t) {
	return(num * t.den == den * t.num);
}

int main() {
	Rational x(2, 7), y, z;
	y = 2;
	y *= x;
	x *= 7; //OK
	x.Show();
	y.Show();
	cout << ((x == y) ? "isti se" : "ne se isti") << endl;
	cout << ((x == 2) ? "isti se" : "ne se isti") << endl; // OK
	//	cout << ((2==y)? "isti se" : "ne se isti") << endl; // Ne moze!!!
}