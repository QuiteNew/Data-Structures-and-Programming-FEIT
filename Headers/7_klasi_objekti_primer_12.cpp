#include <iostream>
using namespace std;
class Rational {
public:
	Rational(int n, int d) : num(n), den(d) { }
	Rational(const Rational& r) : num(r.num), den(r.den)
	{
		cout << "COPY CONSTRUCTOR CALLED\n";
	}
private:
	int num, den;
};

Rational f(Rational r) {	// се повикува copy конструктор за копирање на ? во r
	Rational s = r; 		// се повикува copy конструктор за копирање на r во s
	return s;				// се повикува copy конструктор за копирање на s во ?
}
int main() {
	Rational x(22, 7);
	Rational y(x); 			// се повикува copy конструктор за копирање на x во y
	f(y);
}
