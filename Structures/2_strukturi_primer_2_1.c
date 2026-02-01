#include <stdio.h>
#include <string.h>
struct s
{
	int i;
	char niza[80];
} s, *p;
void main()
{
	p = &s;
	s.i = 10;
	p->i = 20;
	strcpy(p->niza, "Mnogu sakam strukturi");
	printf("%d %d %s\n", s.i, p->i, p->niza);
}
