#include <iostream>
using namespace std;

class X {
public:
	X() { cout << "Default constructor called" << endl; }
	X(int a) :i(a) { cout << "Constructor(" << a << ") called" << endl; }
	~X() { cout << "Destructor for " << i << " called" << endl; }
	void show() const { cout << i << endl; }
private:  int i;
};

int main() {
	X *ip = new X;
	X *jp = new X(2);
	X *pole = new X[4];
	ip->show();
	(*jp).show();
	for (int i = 0; i < 4; i++) {
		cout << "pole[" << i << "] = "; pole[i].show(); }
	delete ip; delete jp;
	delete[] pole;
}
