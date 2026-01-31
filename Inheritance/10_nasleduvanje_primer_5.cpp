#include <iostream>
#include <string>
using namespace std;
class Animal {
public:
	Animal() { cout << "Animal()" << endl; species = "Animal"; }
	Animal(const string s) { cout << "Animal(" << s << ")" << endl; species = s; }
private:	string species;
};
class Primate : public Animal {
public:	Primate() : Animal("Primate") { cout << "Primate()" << endl; }
		Primate(int n) : Animal("Primate") {
			cout << "Primate(" << n << ")" << endl; heartCham = n;
		}
private:	int heartCham;
};
class Human : public Primate {
public:Human() : Primate(4) { cout << "Human()" << endl; }
};
int main() {
	Animal slug; //Opisthobranch Molluscs
	Animal tweety("canary");
	Primate godzilla;
	Primate human(4);
	Human jill;
	return 0;
}
