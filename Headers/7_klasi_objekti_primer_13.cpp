#include <iostream>
using namespace std;
class myclass {
	int i;
public:
	myclass(const myclass &n);
	myclass(int n) : i(n) { cout << "Constructing " << i << "\n"; };
	~myclass() { cout << "Destroying " << i << "\n"; };
	void set_i(int n) { i = n; }
	int get_i() { return i; }
};
myclass::myclass(const myclass &n) {
	i = n.i;
	cout << "Constructing+copying " << i << "\n";
}
void f(myclass ob);

int main() {
	myclass o(1);
	f(o);
	cout << "This is i in main: ";
	cout << o.get_i() << "\n";
	return 0;
}

void f(myclass ob) {
	ob.set_i(2);
	cout << "This is local i: "<<ob.get_i()<<"\n";
}
