/*Using an enumeration type */
#include <stdio.h>

enum months {
	JAN = 1, FEB, MAR, APR, MAY, JUN,
	JUL, AUG, SEP, OCT, NOV, DEC
};

int main()
{
	int month;
	const char *monthName[] = { "", "Januari", "Fevruari",
									"Mart", "April", "Maj",
									"Juni", "Juli", "Avgust",
									"Septemvri", "Oktomvri",
									"Noemvri", "Dekemvri" };
	for (month = JAN; month <= DEC; month++)
		printf("%2d%11s\n", month, monthName[month]);

	printf("%d %d %d %d %d %d\n", bela, zolta, crvena, sina, zelena, crna);
	return 0;	
}