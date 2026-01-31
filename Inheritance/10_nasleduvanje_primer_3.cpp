#include <iostream>
using namespace std;
class BC {
public: 	BC() { x = y = -1; }
protected:	int getX() const { return x; }
			int getY() const { return y; }
private:	int x;
			int y;
};
class DC : public BC {
public:	void write() const { cout << getX()*getY() << endl; }
};
int main() {
	DC d;
//	cout << d.getX() << endl; Ne moze!!!
	d.write();
	return 0;
}
