#include <iostream>
using std::cout;
using std::endl;
struct Vreme { int cas; int min; int sek; };
void printMilitary(const Vreme &);  // prototip
void printStandard(const Vreme &);  // prototip

int main() {
	Vreme vecera;
	vecera.cas = 18; vecera.min = 30; vecera.sek = 0;
	cout << "Vecerata ke bide vo ";
	printMilitary(vecera);
	cout << " voeno vreme,\nkoe e ";
	printStandard(vecera);
	cout << " standardno vreme.\n";
	vecera.cas = 29; vecera.min = 73;
	cout << "\nVreme so pogresni vrednosti: ";
	printMilitary(vecera);
	cout << endl;
	return 0;
}
void printMilitary(const Vreme &t) {
	cout << (t.cas < 10 ? "0" : "") << t.cas << ":" << ( t.min < 10 ? "0" : "" ) << t.min;
}
void printStandard(const Vreme &t) {
	cout << ((t.cas == 0 || t.cas == 12) ? 12 : t.cas % 12) << ":" << (t.min < 10 ? "0" : "") << t.min << ":"
		<< (t.sek < 10 ? "0" : "") << t.sek << (t.cas < 12 ? " AM" : " PM");
}
