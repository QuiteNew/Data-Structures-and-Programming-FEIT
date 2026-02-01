#include <iostream>
#include <cstring>
using namespace std;

class Vozilo {
public:
	Vozilo() { tezina = 0; };
	Vozilo(int wt) { tezina = wt; };
	virtual int VratiTezina() const { return(tezina); }
	virtual void PostaviTezina(int wt) { tezina = wt; }
private:
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
public:
	Kamion() { TezinaPrikolka = 0; };
	Kamion(int TezMasinskiDel, int sp, char const *nm, int PrikolkaTez);
	void PostaviTezina(int engine_wt, int trailer_wt);
	int VratiTezina() const;
private:
	int TezinaPrikolka;
};

Kamion::Kamion(int TezMasinskiDel, int sp, char const *nm, int trailer_wt) : Avtomobil(TezMasinskiDel, sp, nm) {
	TezinaPrikolka = trailer_wt;
}

void Kamion::PostaviTezina(int engine_wt, int trailer_wt) {
	TezinaPrikolka = trailer_wt;
	Avtomobil::PostaviTezina(engine_wt);
}
int Kamion::VratiTezina() const {
	return (Avtomobil::VratiTezina() + TezinaPrikolka);
}


int main()
{
	Vozilo v(1200); // возило тешко 1200
	Kamion t(6000, 115, "Scania", 15000);	// камион Scania
											// со кабина тешка 6000, брзина 115, и приколка тешка 15000
	Vozilo *vp; // generic pointer na Vozilo 
	vp = &v;
	cout << vp->VratiTezina() << endl;
	// ќе се повика Vozilo::VratiTezina() 
	vp = &t;
	cout << vp->VratiTezina() << endl;
	// ќе се повика Kamion::VratiTezina() 
	//cout << vp->VratiBrzina() << endl;	// syntax error: 
											// VratiBrzina() не е член на Vozilo
}

