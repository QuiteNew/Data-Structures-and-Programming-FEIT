#include <iostream>
#include <string>
using namespace std;

class Rabotnik {
public:
	Rabotnik(char *name = "") :ime(name) { }  // Konstruktor
	virtual ~Rabotnik() { }
	static void SetBod(float newbod) { bod = newbod; }
	const string &Ime(void) const { return ime; }
	float VrednostBod(void) const { return bod; }
	void SmeniIme(const string &novoime) { ime = novoime; }
	virtual float Plata(void) const = 0;
	virtual void Show(void) const = 0;
private:
	string ime;	// ime na vraboten
	static float bod;// vrednost na 1 bod vo denari
};

class Direktor : public Rabotnik {
public:
	Direktor(char *ime = "", float plata = 0) : Rabotnik(ime), bod_plata(plata) {}
	~Direktor() { }
	float Plata(void) const { return bod_plata*VrednostBod(); }
	void Show(void) const { cout << Ime() << ' ' << Plata(); }
	void Osnovica(float vrednost) { bod_plata = vrednost; }
private:
	float bod_plata;// plata izrazena vo bodovi 
};
class Mehanicar : public Rabotnik {
public:
	Mehanicar(char *ime = "", float plata_po_cas = 0, int rab_casovi = 0) :
		Rabotnik(ime), satnina(plata_po_cas), casovi(rab_casovi) { }
	~Mehanicar() { }
	float Plata(void) const { return satnina*casovi*VrednostBod(); }
	void Show(void) const { cout << Ime() << ' ' << Plata(); }
	void RabotniCasovi(int cas) { casovi = cas; }
	void Satnica(float vrednost) { satnina = vrednost; }
private:
	float satnina;	// vrednost na eden cas vo bodovi 
	int casovi;	// broj na casovi
};

class Diler : public Rabotnik
{
public:
	Diler(char *ime = "", float prov = 0, int brprod = 0) :
		Rabotnik(ime), bonus(prov), prodazbi(brprod) { }
	~Diler() { }
	float Plata(void) const { return bonus*prodazbi*VrednostBod(); }
	void Show(void) const { cout << Ime() << ' ' << Plata(); }
	void Bonus(float vrednost) { bonus = vrednost; }
	void Prodazbi(int br) { prodazbi = br; }
private:
	float bonus;	// procent od prodazbata koj e za dilerot
	int prodazbi;	// ostvarena prodazba izrazena vo bodovi
};

class Prodavac : public Diler
{
public:
	Prodavac(char *ime = "", float osnova = 0, float prov = 0, int brprod = 0) :
		Diler(ime, prov, brprod), mesecna(osnova) { }
	~Prodavac() { }
	float Plata(void) const { return mesecna*VrednostBod() + Diler::Plata(); }
	void Show(void) const { cout << Ime() << ' ' << Plata(); }
	void Osnovica(float vrednost) { mesecna = vrednost; }
private:
	float mesecna;	// fiksen del od mesecnata plata
};

class Honorarec : public Rabotnik
{
public:
	Honorarec(char *ime = "", float vrednost = 0) :
		Rabotnik(ime), honorar(vrednost) { }
	~Honorarec() { }
	float Plata(void) const { return honorar; }
	void Show(void) const { cout << Ime() << ' ' << Plata(); }
	void Honorar(float vrednost) { honorar = vrednost; }
private:
	float honorar;	// honorar vo denari
};
class Konsultant : public Honorarec
{
public:
	Konsultant(char *ime = "", float osnova = 0, float usluga = 0) :
		Honorarec(ime, osnova), bonus(usluga) { }
	~Konsultant() { }
	float Plata(void) const { return bonus + Honorarec::Plata(); }
	void Show(void) const { cout << Ime() << ' ' << Plata(); }
	void Bonus(float vrednost) { bonus = vrednost; }
private:
	float bonus;	// dodaten varijabilen del na platata vo denari
};

float Rabotnik::bod = 10.0;

int main()
{
	Rabotnik::SetBod(12.0);
	Rabotnik *Firma[] = {
		new Direktor("direktor1",1000.0),
		new Mehanicar("mehanicar1",3.5,45),
		new Prodavac("prodavac1",300.0,30.0,5),
		new Prodavac("prodavac2",400.0,25.0),
		new Diler("diler1",50.0,3),
		new Honorarec("honorarec1",100.0),
		new Konsultant("konsultant1",500.0),
		0 };

	float total = 0.0;
	Rabotnik *r;
	for (int i = 0; r = Firma[i]; i++)
	{
		r->Show(); cout << endl;
		total += r->Plata();
	}
	cout << "Vkupno za isplata " << total << endl;
	for (int i = 0; Firma[i]; delete Firma[i++]);
	return(0);
}




