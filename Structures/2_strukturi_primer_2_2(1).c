#include <stdio.h>

typedef struct point {
	float x;
	float y;
} tocka;

typedef struct rect {
	tocka pt1;
	tocka pt2;
} pravoagolnik;

tocka makepoint(float x, float y)
{
	tocka temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

pravoagolnik makerect(tocka x, tocka y)
{
	pravoagolnik temp;
	temp.pt1 = x;
	temp.pt2 = y;
	return temp;
}

/* ptinrect: vraka 1 ako p e vo r, 0 inaku */
int ptinrect(tocka p, pravoagolnik r)
{
	return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

tocka centar(pravoagolnik p)
{
	return(makepoint((p.pt1.x + p.pt2.x) / 2, (p.pt1.y + p.pt2.y) / 2));
}

float povrsina(pravoagolnik r)
{
	return((r.pt2.x - r.pt1.x)*(r.pt2.y - r.pt1.y));
}

int main()
{
	tocka pt1, sredina; pravoagolnik prozor1, prozor2;
	pravoagolnik ekran = { { 2,3 },{ 4,5 } };
	pt1 = makepoint(0, 0);
	prozor1.pt1 = pt1;
	prozor1.pt2 = makepoint(5, 5);
	sredina = centar(ekran);
	prozor2 = makerect(sredina, makepoint(5, 5));

	printf("Tockata (%4.2f,%4.2f) se naogja %s pravoagolnikot (%4.2f, %4.2f) : (%4.2f, %4.2f)\n", sredina.x, sredina.y, (ptinrect(sredina, prozor1) ? "vo" : "nadvor od"), prozor1.pt1.x, prozor1.pt1.y, prozor1.pt2.x, prozor1.pt2.y);
	printf("Tockata (%4.2f,%4.2f) se naogja %s pravoagolnikot (%4.2f, %4.2f) : (%4.2f, %4.2f)\n", pt1.x, pt1.y, (ptinrect(pt1, prozor2) ? "vo" : "nadvor od"), prozor2.pt1.x, prozor2.pt1.y, prozor2.pt2.x, prozor2.pt2.y);
}

