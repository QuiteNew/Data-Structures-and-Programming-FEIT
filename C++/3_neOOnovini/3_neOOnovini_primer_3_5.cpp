#include <iostream>
using namespace std;
void show(int val)
{
	cout << "Integer: " << val << endl;
}
void show(double val)
{
	cout << "Double: " << val << endl;
}
void show(char *val)
{
	cout << "String: " << val << endl;
}

int main()
{
	show(12);
	show(3.1415);
	show("Hello World!");
	return 0;
}
