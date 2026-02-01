#include <iostream>

namespace A
{
	int i = 0;
	namespace X
	{
		int i = 1;
		char c = 'x';
	}
	namespace Y
	{
		int i = 2;
		char c = 'y';
	}
}
namespace B
{
	int i = 3;
	int j = 7;
}
namespace C
{
	using namespace B;
	int i = 4;
	int j = 8;
}
namespace D
{
	int j = 8;
}
int i = 5;
using namespace std;

int main()
{
	cout << i << endl;            // global i
	cout << A::X::i << endl;      // A::X::i
	cout << A::Y::i << endl;      // A::Y::i
	cout << B::i << endl;         // B::i
	cout << C::i << endl;         // C::i

	using namespace A;
	//   cout << i << endl; // *** Error: ambiguous symbol global i or A::i
	cout << X::c << endl;         // A::X::c
	cout << Y::c << endl;         // A::Y::c
	{
		using namespace C;
		//      cout << j << endl; // *** Error: ambiguous symbol B::j or C::j
	}
	{
		int j;
		cin >> j;                  // local j
		if (j)
		{
			using namespace A::X;
			cout << c << endl;      // A::X::c
		}
		else
		{
			using namespace A::Y;
			cout << c << endl;      // A::Y::c
		}
	}
	using namespace D;
	cout << j << endl;            // D::j
	return 0;
}

