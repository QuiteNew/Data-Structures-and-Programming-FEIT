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
	String &operator=(const String &);
	void Show(void) const { cout << cptr; }
};

inline String::String(const char * a_cptr)
{
	cptr = new char[strlen(a_cptr) + 1];
	strcpy(cptr, a_cptr);
}

inline String::~String()
{
	delete[] cptr;
}

String &String::operator =(const String &from) {
	delete[] cptr;
	cptr = new char[strlen(from.cptr) + 1];
	strcpy(cptr, from.cptr);
	return *this;
}


int main()
{
	const String b("World");
	String c, d("Hello");
	{
		String a(d);
		a.Show(); cout << ' ';
		b.Show(); cout << endl;
		c = a; d = b;
		c.Show(); cout << ' ';
		d.Show(); cout << endl;
	}
	c.Show(); cout << ' ';
	d.Show(); cout << endl;

	String A("xyz"), B("abc");
	B = A; // ???

	return(0);
}
