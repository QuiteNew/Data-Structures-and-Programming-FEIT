#include <iostream>
using namespace std;
class X {
	int a;
public:
	X(int j) { a = j; }
	int geta() { return a; }
};
int main() {
	X ob = 99; 			// пренесува 99 за j
	cout << ob.geta();	// прикажува 99
	return 0;
}
