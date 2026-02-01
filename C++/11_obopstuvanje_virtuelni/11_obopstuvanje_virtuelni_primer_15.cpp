#include <iostream>
#include <string>
using namespace std;

class Rabotnik
{
public:
	Rabotnik(char *name = "") :ime(name) { }  // Konstruktor
	virtual ~Rabotnik() { }
	const string &Ime(void) const { return ime; }
	void SmeniIme(const string &novoime) { ime = novoime; }
	virtual float Plata(void) const = 0;
	virtual void Show(void) const = 0;
private:
	string ime; // ime na vraboten
};

class Vraboten : public Rabotnik
{
public:
	Vraboten(char *name = "") :Rabotnik(name) { }  // Konstruktor
	virtual ~Vraboten() { }
	static void SetBod(float newbod) { bod = newbod; }
	virtual float Plata(void) const = 0;
	virtual void Show(void) const = 0;
protected:
	static float bod; // vrednost na 1 bod vo denari
};

class Sorabotnik : public Rabotnik
{
public:
	Sorabotnik(char *name = "") :Rabotnik(name) { }  // Konstruktor
	virtual ~Sorabotnik() { }
	virtual float Plata(void) const = 0;
	virtual void Show(void) const = 0;
};

class Direktor : virtual public Vraboten
{
public:
	Direktor(char *ime = "", float plata = 0) : Vraboten(ime), bod_plata(plata) {}
	~Direktor() { }
	float Plata(void) const { return bod_plata*bod; }
	void Show(void) const { cout << Ime() << ' ' << Plata(); }
	void Osnovica(float vrednost) { bod_plata = vrednost; }
private:
	float bod_plata; // plata izrazena vo bodovi
};

class Mehanicar : public Vraboten
{
public:
	Mehanicar(char *ime = "", float plata_po_cas = 0, int rab_casovi = 0) :
		Vraboten(ime), satnina(plata_po_cas), casovi(rab_casovi) { }
	~Mehanicar() { }
	float Plata(void) const { return satnina*casovi*bod; }
	void Show(void) const { cout << Ime() << ' ' << Plata(); }
	void RabotniCasovi(int cas) { casovi = cas; }
	void Satnica(float vrednost) { satnina = vrednost; }
private:
	float satnina; // vrednost na eden cas vo bodovi
	int casovi;	 // broj na casovi
};

class Diler : virtual public Vraboten
{
public:
	Diler(char *ime = "", float prov = 0, int brprod = 0) :
		Vraboten(ime), bonus(prov), prodazbi(brprod) { }
	~Diler() { }
	float Plata(void) const { return bonus*prodazbi*bod; }
	void Show(void) const { cout << Ime() << ' ' << Plata(); }
	void Bonus(float vrednost) { bonus = vrednost; }
	void Prodazbi(int br) { prodazbi = br; }
private:
	float bonus;	 // procent od prodazbata koj e za dilerot
	int prodazbi;	 // ostvarena prodazba izrazena vo bodovi
};

class Prodavac : public Direktor, public Diler
{
public:
	Prodavac(char *ime = "", float osnova = 0, float prov = 0, int brprod = 0)
	{
		SmeniIme(ime); Bonus(prov); Prodazbi(brprod); Osnovica(osnova);
	}
	~Prodavac() { }
	float Plata(void) const { return Direktor::Plata() + Diler::Plata(); }
	void Show(void) const { cout << Ime() << ' ' << Plata(); }
};

class Honorarec : public Sorabotnik {
public:
	Honorarec(char *ime = "", float vrednost = 0) :
		Sorabotnik(ime), honorar(vrednost) { }
	~Honorarec() { }
	float Plata(void) const { return honorar; }
	void Show(void) const { cout << Ime() << ' ' << Plata(); }
	void Honorar(float vrednost) { honorar = vrednost; }
private:
	float honorar; // honorar vo denari
};

class Konsultant : public Honorarec {
public:
	Konsultant(char *ime = "", float osnova = 0, float usluga = 0) :
		Honorarec(ime, osnova), bonus(usluga) { }
	~Konsultant() { }
	float Plata(void) const { return bonus + Honorarec::Plata(); }
	void Show(void) const { cout << Ime() << ' ' << Plata(); }
	void Bonus(float vrednost) { bonus = vrednost; }
private:
	float bonus; // dodaten varijabilen del na platata vo denari
};

float Vraboten::bod = 10.0;
int main()
{
	Vraboten::SetBod(12.0);
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