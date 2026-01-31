#include <iostream>
using namespace std;
class Rational {
public:
	Rational(int n = 0, int d = 1) : num(n), den(d) { reduce(); }
	Rational(const Rational& r) : num(r.num), den(r.den) { }
	void print() { cout << num << '/' << den; }
private:
	int num, den;
	int gcd(int m, int n) { if (n == 0) return m; return gcd(n, m%n); }
	void reduce() { int g = gcd(num, den); num /= g; den /= g; }
};
int main() {
	Rational x(100, 360);
	Rational y(x); //Rational y=x;
	cout << "X = "; x.print(); cout << ", y = "; y.print();
}


