#include <iostream>
#include <cstring>
using namespace std;
class Person {
	enum { NameLen = 20, AddrLen = 30, PhoneLen = 10 };
public: // interface functions
	Person(const char *n = "", const char *a = "-nepoznata-", const char *p = "-nepoznato-");
	void setName(const char *n);
	void setAddress(const char *a);
	void setPhone(const char *p);
	const char *getName() const;
	const char *getAddress() const;
	const char *getPhone() const;
	void Show() const;
private:
	char name[NameLen + 1]; // name of person
	char addr[AddrLen + 1]; // address field
	char phone[PhoneLen + 1]; // telephone number
};

Person::Person(const char *n, const char *a, const char *p) {   /* isto so prethodno */ }

void Person::setName(const char *n) {   /* isto so prethodno */ }
void Person::setAddress(const char *a) {   /* isto so prethodno */ }
void Person::setPhone(const char *p) {   /* isto so prethodno */ }

const char *Person::getName() const { return(name); }
const char *Person::getAddress() const { return(addr); }
const char *Person::getPhone() const { return(phone); }

void Person::Show() const {
	cout << name << " " << addr << " " << phone << endl;
}

int main() {
	Person P1("Nekoj", "somebody@network.net");
	const Person P2("Drug", "other@else.com", "5551234");
	Person P3;
	char *p;

	cout << P1.getName() << endl; //OK
	P1.setName("Ovoj"); //OK
	P1.Show(); //OK

	P2.Show(); //OK
	cout << P2.getName() << endl; //OK
	P3 = P2;
	p = P2.getPhone(); //Ne moze!!!
}

