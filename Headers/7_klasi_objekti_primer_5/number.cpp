#include <iostream>
#include <cstring>				// This is the same as string.h in C
using namespace std;
#include "number.h" 
Numbers::Numbers() {			// Constructor member function
	strcpy(name, "Unknown"); a = 0; b = 0.0;
}
void Numbers::display() {		// Member function 
	cout << "\nThe name is " << name << "\n";
	cout << "The numbers are " << a << " and " << b << endl;
}
void Numbers::update() {		// Member function
	cout << "Enter name" << endl;
	cin.getline(name, 30);
	cout << "Enter a and b" << endl;
	cin >> a >> b;
}

