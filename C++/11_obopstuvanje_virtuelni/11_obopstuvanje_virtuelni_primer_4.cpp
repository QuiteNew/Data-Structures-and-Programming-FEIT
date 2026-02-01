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
	Vozilo v(1000), *vp;
	Zemjeno l(1200, 145), *lp; // l e Zemjeno, но истовремено и Vozilo
	Avtomobil a(790, 220, "Fiat"), *ap; // a e Avtomobil, но истовремено и Zemjeno и Vozilo
	Kamion t(2600, 85, "Scania", 7000);
	v = l; // ова е OK, но, ќе се ископира само l.weight во v.weight
		   // l=v не може, што да се ископира во l.speed ???
	v = a; v = t; l = a; l = t; a = t; // се ОК, но, a=v, a=l или t=a не може
	vp = &v;                // покажувач од базната класа може 
							// да покажува кон објекти од базната класа
	vp = &l; vp = &a; // но, и кон објекти од класи изведени од неа
	lp = &l; lp = &a; // спротивното не е можно: ap=&l или pl=&v
	Zemjeno &lr = a;

	Vozilo *vpl, *vpa, *vpt;
	Avtomobil *apt; Kamion *tpt;
	Zemjeno l(1200, 145);
	Avtomobil a(790, 220, "Fiat");
	Kamion t(2600, 85, "Scania", 7000);
	vpl = &l; vpa = &a; vpt = &t; apt = &t; tpt = &t;
	cout << vpl->VratiTezina() << endl; // се повикува Vozilo::VratiTezina()
	cout << vpa->VratiTezina() << endl; // се повикува Vozilo::VratiTezina()
										// vpa->VratiBrzina() не може да се повика 
										// иако vpa покажува кон објект од класата Avtomobil
	cout << vpt->VratiTezina() << endl; // се повикува Vozilo::VratiTezina()
	cout << apt->VratiBrzina() << endl; // се повикува Avtomobil::VratiBrzina()
	cout << apt->VratiTezina() << endl; // се повикува Avtomobil::VratiTezina()
										// односно Vozilo::VratiTezina()
	cout << tpt->VratiTezina() << endl; // се повикува Kamion::VratiTezina()

	Kamion truck(2600, 85, "Scania", 7000);
	Vozilo *vp;
	vp = &truck; // vp sega pokazuva kon objekt Kamion
	Kamion *trp;
	trp = reinterpret_cast<Kamion *>(vp);
	cout << "Kamion tip: " << trp->VratiIme() << endl;
	cout << "Kamion tezina: " << trp->VratiTezina() << endl;
	return 0;
}
