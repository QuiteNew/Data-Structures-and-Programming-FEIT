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
	const char *getName();
	const char *getAddress();
	const char *getPhone();
	void Show();
private:
	char name[NameLen + 1]; // name of person
	char addr[AddrLen + 1]; // address field
	char phone[PhoneLen + 1]; // telephone number
};

Person::Person(const char *n, const char *a, const char *p) {
	strncpy(name, n, NameLen); name[NameLen] = 0;
	strncpy(addr, a, AddrLen); addr[AddrLen] = 0;
	strncpy(phone, p, PhoneLen); phone[PhoneLen] = 0;
}

void Person::setName(const char *n) { strncpy(name, n, NameLen); name[NameLen] = 0; }
void Person::setAddress(const char *a) { strncpy(addr, a, AddrLen); addr[AddrLen] = 0; }
void Person::setPhone(const char *p) { strncpy(phone, p, PhoneLen); phone[PhoneLen] = 0; }

const char *Person::getName() { return(name); }
const char *Person::getAddress() { return(addr); }
const char *Person::getPhone() { return(phone); }

void Person::Show() { cout << name << " " << addr << " " << phone << endl; }

int main() {
	Person P1("Nekoj", "somebody@network.net");
	const Person P2("Drug", "other@else.com", "5551234");
	Person P3;
	char *p;
	cout << P1.getName() << endl; //OK
	P1.setName("Ovoj"); //OK
	P1.Show(); //OK

	P2.Show(); //Ne moze!!!
	cout << P2.getName() << endl; //Ne moze!!
	P3 = P2;
	p = P2.getPhone(); //Ne moze!!!
}

