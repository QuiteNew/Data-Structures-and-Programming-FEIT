#include <iostream>
#include <cstring> 		// This is the same as string.h in C
using namespace std;
#include "number.h" 
int main() {			// Main program
	Numbers no1, no2;  	// Create two objects of the class "Numbers"
	no1.update();		// Update the values of
						// the data members
	no1.display();		// Display the current 
	no2.display();		// values of the objects
}
