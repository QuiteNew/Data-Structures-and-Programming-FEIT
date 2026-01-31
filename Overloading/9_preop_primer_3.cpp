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

int main()
{
	const String b("World");
	String c, d("Hello");

	{
		const String a(d), *p = &d;
		a.Show(); cout << ' ';
		b.Show(); cout << endl;
		c = "HELLO"; // ke raboti
		d = *p;
		c.Show(); cout << ' ';
		d.Show(); cout << endl;
	}
	c.Show(); cout << ' ';
	d.Show(); cout << endl;
	return(0);
}



