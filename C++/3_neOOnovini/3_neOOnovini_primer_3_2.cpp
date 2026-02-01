#include <iostream>
using namespace std;
int ccc = 987;
int main()
{
	int ccc = 123;
	cout << "main   ccc=" << ccc << endl;
	cout << "Global ccc=" << ::ccc << endl;
	{
		int ccc = 456;
		cout << "Inner  ccc=" << ccc << endl;
		cout << "Global ccc=" << ::ccc << endl;
		{
			int ccc = 789;
			cout << "Innest ccc=" << ccc << endl;
			cout << "Global ccc=" << ::ccc << endl;
			::ccc = 321;
		}
		cout << "Inner  ccc=" << ccc << endl;
		cout << "Global ccc=" << ::ccc << endl;
	}
	cout << "main   ccc=" << ccc << endl;
	cout << "Global ccc=" << ::ccc << endl;
}
