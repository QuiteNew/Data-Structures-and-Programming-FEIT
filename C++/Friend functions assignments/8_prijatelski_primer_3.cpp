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
	return(0);
}


