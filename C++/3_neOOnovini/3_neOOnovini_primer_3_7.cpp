#include <iostream>
using namespace std;

int main()
{
	int i;
	int x = 123;
	int &y = x;

	cout << "x= " << x << " y= " << y << endl;

	x = 23;
	cout << "x= " << x << " y= " << y << endl;

	x++;
	cout << "x= " << x << " y= " << y << endl;
	return 0;
}
