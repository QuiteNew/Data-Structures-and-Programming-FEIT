#include <iostream>
using namespace std;
class BC {
public:
	void g(int) { cout << "BC::g()" << endl; }
	void h(double) { cout << "BC::h()" << endl; }
};
class DC : public BC {
public:
	void g(int) { cout << "DC::g()" << endl; }
	void h(char[]) { cout << "DC::h()" << endl; }
};
int main() {
	DC d;
	d.h("Boffo!");
	d.h(707.7); //Error! 
	d.BC::h(707.7);
	d.g(3);
	d.BC::g(4);
	return 0;
}
