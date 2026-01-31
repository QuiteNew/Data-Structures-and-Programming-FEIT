#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
	char * cptr;
public:
	String(const char * = "");
	~String();
	String(const String &); //copy
	String &operator=(const String &);
	void Show(void) const { cout << cptr; }
	bool operator==(const String &a) const { return !strcmp(cptr, a.cptr); }
	bool operator!=(const String &a) const { return strcmp(cptr, a.cptr); }
	friend bool operator==(const char *a, const String &b);
};

String &String::operator =(const String &from)
{
	if (this == &from)
		return *this;
	else
	{
		delete[] cptr;
		cptr = new char[strlen(from.cptr) + 1];
		strcpy(cptr, from.cptr);
		return *this;
	}
}

inline String::String(const String &from)
{
	cptr = new char[strlen(from.cptr) + 1];
	strcpy(cptr, from.cptr);
}

inline String::String(const char * a_cptr)
{
	cptr = new char[strlen(a_cptr) + 1];
	strcpy(cptr, a_cptr);
}

inline String::~String()
{
	delete[] cptr;
}

bool operator==(const char *a, const String &b) { return!strcmp(a, b.cptr); }

int main() {
	const String b("World");
	String c, d("Hello");
	const String a(d), *p = &d;
	c = "HELLO"; d = *p;
	a.Show(); cout << " " << (a == b ? "==" : "=/=") << " "; b.Show(); cout << endl;
	c.Show(); cout << " " << (c != d ? "!=" : "ne e !=") << " "; d.Show(); cout << endl;
	if (c == "HELLO") // moze
	{
		c.Show(); cout << "==HELLO" << endl;
	}
	//if("HELLO"==c) // vaka NE moze!!! сега може
	return(0);
}
