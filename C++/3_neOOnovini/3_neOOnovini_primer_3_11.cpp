#include <iostream>
#include <cmath>
namespace RAD
{
	double angle;
	double sinus(double x) // arg in rad
	{
		return(std::sin(x));
	}
}

namespace DEG
{
	int angle;
	double sinus(double x) // arg in deg
	{
		return(std::sin(x*M_PI / 180));
	}
}

using namespace std;
int main()
{
	{
		using namespace RAD;
		angle = 1.05; //RAD::angle=1.05 rad
		cout << " sinus(" << angle << "rad)=" << sinus(angle) << endl;
	}
	{
		using namespace DEG;
		angle = 60; //DEG::angle=60 deg
		cout << " sinus(" << angle << "deg)=" << sinus(angle) << endl;
	}
	return 0;
}
