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
public: // konstruktori
	Zemjeno() { brzina = 0; }	
	Zemjeno(int wt, int sp) : Vozilo(wt) { brzina = sp; }
	void PostaviBrzina(int sp) { brzina = sp; } // interfejs
	int VratiBrzina() const { return brzina; }  // interfejs
private:
	int brzina; 				// podatoci
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

class Kamion : public Avtomobil {
public: // konstruktori
	Kamion() { TezinaPrikolka = 0; };
	Kamion(int TezMasinskiDel, int sp, char const *nm, int PrikolkaTez);
	// interfejs za postavuvanje na dvete polinja za tezina
	void PostaviTezina(int engine_wt, int trailer_wt);
	// I vrakanje na vkupnata tezina
	int VratiTezina() const;
private: // podatoci
	int TezinaPrikolka;
};
// primer na konstruktor
Kamion::Kamion(int TezMasinskiDel, int sp, char const *nm, int trailer_wt) : Avtomobil(TezMasinskiDel, sp, nm) {
	TezinaPrikolka = trailer_wt;
}

void Kamion::PostaviTezina(int engine_wt, int PrikolkaTez) {
	TezinaPrikolka = PrikolkaTez;
	Avtomobil::PostaviTezina(engine_wt);
	// zabeleska Avtomobil:: e potrebno
}

int Kamion::VratiTezina() const {
	return (Avtomobil::VratiTezina() + TezinaPrikolka);
}

int main() {
	Zemjeno veh(1200, 145);
	Kamion lorry(3000, 120, "Juggernaut", 2500);
	lorry.Vozilo::PostaviTezina(4000);
	cout << endl;
	cout << "Kamionot tezi " << lorry.Vozilo::VratiTezina() << endl;
	cout << "Kamionot + prikolkata tezat " << lorry.VratiTezina() << endl;
	cout << "Negovata brzina iznesuva " << lorry.VratiBrzina() << endl;
	cout << "Kamionot e od markata " << lorry.VratiIme() << endl;
	return (0);
}


