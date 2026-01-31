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

	operator char * () { return cptr; }
	friend ostream &operator<<(ostream &output, const String & a)
		{ return output << a.cptr; }
	
	friend bool operator==(const String &a, const String &b)
		{ return !strcmp(a.cptr, b.cptr); }
	friend bool operator==(const char *a, const String &b)
		{ return !strcmp(a, b.cptr); }
	friend bool operator==(const String &a, const char *b)
		{ return !strcmp(a.cptr, b); }
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

int main() {
	String A("Hello");
	cout << "Dolzinata na \"" << A << "\" e " << strlen(A) << endl;
	if (A == "Hello") // moze
		cout << A << "==Hello" << endl;
	else 
		cout << A << "!=Hello" << endl;
	if ("Hello" == A) // moze
		cout << "Hello==" << A << endl;
	else
		cout << "Hello" << "!=" << A << endl;
	return(0);
}
