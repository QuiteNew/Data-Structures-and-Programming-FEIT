#include <iostream>
using namespace std;

class Vozilo {
public: // konstruktori
	Vozilo() { tezina = 0; };
	Vozilo(int wt) { tezina = wt; };
	// interfejs
	int VratiTezina() const { return tezina; };
	void PostaviTezina(int wt) { tezina = wt; };
private:
	// podatoci
	int tezina;
};

class Zemjeno : public Vozilo {
public:
	Zemjeno() {	brzina = 0; }								// konstruktori
	Zemjeno(int wt, int sp) : Vozilo(wt) { brzina = sp; } 	// konstruktori
	void PostaviBrzina(int sp) { brzina = sp; };			// interfejs
	int VratiBrzina() const { return brzina; }; 			// interfejs
private:
	int brzina; 											// podatoci
};

class Avtomobil : public Zemjeno {
public:
	Avtomobil() { ime = new char[1];  ime = ""; }; // konstruktor
	Avtomobil(int wt, int sp, char const *nm) : Zemjeno(wt, sp) { ime = new char[strlen(nm) + 1]; strcpy(ime, nm); }; // konstruktor
	Avtomobil(Avtomobil const &other) : Avtomobil(other.VratiTezina(), other.VratiBrzina(), other.VratiIme()) {}; // copy konstruktor
	Avtomobil const &operator=(Avtomobil const &other) { PostaviBrzina(other.VratiBrzina()); PostaviTezina(other.VratiTezina()); PostaviIme(other.VratiIme()); }; //dodeluvanje
	~Avtomobil() { delete[] ime; }; // destructor
	char const *VratiIme() const { return ime; }; // interfejs
	void PostaviIme(char const *nm) { delete[] ime; ime = new char[strlen(nm) + 1]; strcpy(ime, nm); };
private:
	char *ime; // podatoci
};

Zemjeno veh(1200, 145);
int main() {
	cout << "Voziloto tezi " << veh.VratiTezina() << endl;
	cout << "Negovata brzina iznesuva " << veh.VratiBrzina() <<endl;
	return (0);
}


