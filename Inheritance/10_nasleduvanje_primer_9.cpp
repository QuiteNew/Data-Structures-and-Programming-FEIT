#include <iostream>
using namespace std;
class BC {
public:	void setX(int x) { this->x = x; }
protected:	int getX() const { return x; }
private:	int x;
};
class DC : public BC {
public:		void add2() { int c = getX(); setX(c + 2); }
};
int main() {
	DC d;
	d.setX(3);
	cout << d.getX() << endl;  // Error!
	d.x = 77;  // Error!
	d.add2();
	return 0;
};
