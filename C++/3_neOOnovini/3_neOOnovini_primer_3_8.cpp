#include <iostream>
using namespace std;
int mynum = 100;
inline int &num()
{
	return mynum;
}
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
	y++;
	cout << "x= " << x << " y= " << y << endl;
	i = num();
	cout << "i= " << i << " mynum= " << mynum << endl;
	num() = 5;
	cout << "mynum= " << mynum << " num()= " << ++num() << endl;
	return 0;
}
