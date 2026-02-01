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

class Zemjeno : virtual public Vozilo {
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

class Trejler
{
public:
	Trejler() {}
	Trejler(int twt) : tezinap(twt) {}
	void PostaviTezina(int twt) { tezinap = twt; }
	int VratiTezina() const { return tezinap; }
private: // podatoci
	int tezinap;
};

class Kamion : public Avtomobil, public Trejler {
public: // konstruktori
	Kamion() {}
	Kamion(int engine_wt, int sp, char const *nm, int trailer_wt) :
		Avtomobil(engine_wt, sp, nm), Trejler(trailer_wt) {}
	void PostaviTezina(int engine_wt, int trailer_wt) {
		Trejler::PostaviTezina(trailer_wt);
		Avtomobil::PostaviTezina(engine_wt);
	}
	int VratiTezina() const { return (Avtomobil::VratiTezina() + Trejler::VratiTezina()); }
	// bez podatoci
};

class Vodno : virtual public Vozilo {
public: // konstruktori
	Vodno() {}
	Vodno(int wt, int l) : Vozilo(wt), dolzina(l) {}
	void PostaviDolzina(int l) { dolzina = l; }
	int VratiDolzina() const { return dolzina; }
private: // podatoci
	int dolzina;
};

class Amfibija : public Avtomobil, public Vodno {
public:
	Amfibija() {}
	Amfibija(int wt, int sp, char const *nm, int len)
	{
		PostaviIme(nm); PostaviBrzina(sp);
		PostaviDolzina(len); PostaviTezina(wt);
	}
};

int main() {
	Amfibija am(2500, 35, "T72", 7);
	cout << "Vehicle weighs " << am.VratiTezina() << endl;
	return (0);
}
