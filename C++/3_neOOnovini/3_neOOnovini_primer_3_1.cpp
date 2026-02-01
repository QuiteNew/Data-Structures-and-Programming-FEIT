#include <iostream>
using namespace std;

enum odgovor { NE, DA, MOZEBI };
int main()
{
	const int SIZE = 5;
	odgovor cs[SIZE];
	cout << "The size of cs is "
		<< sizeof cs << endl;
	cs[0] = NE;
	cs[1] = DA;
	cs[2] = MOZEBI;
	cout << cs[0] << cs[1]
		<< cs[2] << endl;
	return 0;
}