#include <iostream>
using namespace std;

class ST {
public:
	int x, y; // секој објект ќе има сопствени x и y
	static int z; // z е единствено - заедничко за сите објекти
};

int ST::z = -1; // иницијализација
				// ST::z постои и без да постојат објекти од класата
int main()
{
	ST a, b;
	a.x = 1; a.y = 2;
	cout << a.x << ' ' << a.y << ' ' << a.z << endl;
	a.z = 0;
	b.x = 6; b.y = 7;
	cout << b.x << ' ' << b.y << ' ' << b.z << endl;

	return(0);
}
