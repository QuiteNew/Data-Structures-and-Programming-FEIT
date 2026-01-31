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
	bool operator==(const String &a) const { return !strcmp(cptr, a.cptr); };
	bool operator!=(const String &a) const { return strcmp(cptr, a.cptr); };

	operator char * () { return cptr; }
	friend ostream &operator<<(ostream &output, const String & a)
	{
		return output << a.cptr;
	};
	friend bool operator==(const String &a, const String &b)
	{
		return !strcmp(a.cptr, b.cptr);
	};
	friend bool operator==(const char *a, const String &b)
	{
		return !strcmp(a, b.cptr);
	};
	friend bool operator==(const String &a, const char *b)
	{
		return !strcmp(a.cptr, b);
	};

	friend String operator+(const String& a, const String& b)
	{
		String tmp;
		delete[] tmp.cptr;
		tmp.cptr = new char[strlen(a.cptr) + strlen(b.cptr) + 1];
		strcpy(tmp.cptr, a.cptr);
		strcat(tmp.cptr, b.cptr);
		return tmp;
	}

	String& operator +=(const String &from) {
		char *tmp;
		tmp = new char[strlen(cptr) + strlen(from.cptr) + 1];
		strcpy(tmp, cptr);
		strcat(tmp, from.cptr);
		delete[] cptr;
		cptr = tmp;
		return *this;
	}

	friend String operator+(const String & a, const char * b)
	{
		String tmp;
		delete[] tmp.cptr;
		tmp.cptr = new char[strlen(a.cptr) + strlen(b) + 1];
		strcpy(tmp.cptr, a.cptr);
		strcat(tmp.cptr, b);
		return tmp;
	}

	friend String operator+(const char * a, const String & b)
	{
		String tmp;
		delete[] tmp.cptr;
		tmp.cptr = new char[strlen(a) + strlen(b.cptr) + 1];
		strcpy(tmp.cptr, a);
		strcat(tmp.cptr, b.cptr);
		return tmp;
	}
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
	String A("Hello"), B("World"), C, D(A);
	C = A + B;
	cout << C << endl;
	C = A + " " + B;
	cout << C << endl;
	D += " ";
	D += A;
	cout << D << endl;
	return(0);
}





