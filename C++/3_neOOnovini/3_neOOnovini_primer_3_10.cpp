#include <iostream>
using namespace std;

struct bigone
{
	int key;
	char text[1000];
} bo = { 123, "This is a big structure" };

// ---- Three functions that have the structure as a parameter
void valfunc(bigone vl);
void ptrfunc(const bigone *pl);
void reffunc(const bigone &rl);

int main()
{
	valfunc(bo);    // Passing the variable itself
	ptrfunc(&bo);   // Passing the address of the variable
	reffunc(bo);    // Passing a reference to the variable
	return 0;
}

// --- Pass by value
void valfunc(bigone vl)
{
	cout << endl << vl.key;
	cout << endl << vl.text;
}

// --- Pass by pointer
void ptrfunc(const bigone *pl)
{
	cout << endl << pl->key;      // Pointer notation
	cout << endl << pl->text;
}

// --- Pass by reference
void reffunc(const bigone &rl)
{
	cout << endl << rl.key;       // Reference notation
	cout << endl << rl.text;
}

