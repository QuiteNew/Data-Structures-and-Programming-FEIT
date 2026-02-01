#include <iostream>
using namespace std;

void swapByVal(int a, int b)
{
	int t = a; a = b; b = t;
}

void swapByPtr(int *a, int *b)
{
	int t = *a; *a = *b; *b = t;
}

void swapByRef(int &a, int &b)
{
	int t = a; a = b; b = t;
}

int main()
{
	int x = 1, y = 2;
	cout << "             Initial: x="
		<< x << " y=" << y << endl;
	swapByVal(x, y);
	cout << "After swapByVal(x,y): x="
		<< x << " y=" << y << endl << endl;

	x = 1, y = 2;
	cout << "               Initial: x="
		<< x << " y=" << y << endl;
	swapByPtr(&x, &y);
	cout << "After swapByVal(&x,&y): x="
		<< x << " y=" << y << endl << endl;

	x = 1, y = 2;
	cout << "             Initial: x="
		<< x << " y=" << y << endl;
	swapByRef(x, y);
	cout << "After swapByRef(x,y): x="
		<< x << " y=" << y << endl;
	return 0;
}

