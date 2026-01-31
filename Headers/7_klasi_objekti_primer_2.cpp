#include <iostream>
using std::cout;
using std::endl;
struct Vreme {
	int cas; int min; int sek;
	void printMilitary(), printStandard();
};

int main() {
	Vreme vecera;
	vecera.cas = 18; vecera.min = 30; vecera.sek = 0;
	cout << "Vecerata ke bide vo ";
	vecera.printMilitary();
	cout << " voeno vreme,\nkoe e ";
	vecera.printStandard();
	cout << " standardno vreme.\n";
	vecera.cas = 29; vecera.min = 73;
	cout << "\nVreme so pogresni vrednosti: ";
	vecera.printMilitary();
	cout << endl;
	return 0;
}
void Vreme::printMilitary() {
	cout << (cas < 10 ? "0" : "") << cas << ":" << ( min < 10 ? "0" : "" ) << min;
}
void Vreme::printStandard() {
	cout << ((cas == 0 || cas == 12) ? 12 : cas % 12) << ":" << (min < 10 ? "0" : "") << min << ":"
		<< (sek < 10 ? "0" : "") << sek << (cas < 12 ? " AM" : " PM");
}
