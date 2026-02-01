#include <iostream>
using namespace std;

class Shape { // Abstract class
public:
	virtual void Draw() const = 0;
};
void Shape::Draw() const { cout << "drawing "; }

class Circle : public Shape {
public:
	Circle(float _x, float _y, float _r) : x(_x), y(_y), r(_r) { }
	void Draw() const // still must override the pure virtual function
	{
		Shape::Draw(); cout << "Circle (" << x << ',' << y << ',' << r << ')' << endl;
	}
private: float x, y, r;
};

class Rectangle : public Shape {
public:
	Rectangle(float _x, float _y, float _w, float _h) : x(_x), y(_y), w(_w), h(_h) {}
	void Draw() const // still must override the pure virtual function
	{
		Shape::Draw(); cout << "Rectangle (" << x << ',' << y << ',' << w << ',' << h << ')' << endl;
	}
private: float x, y, w, h;
};

int main() {
	// ! Shape s; // не може да се декларира објект од апстрактна класа
	Shape *p; // но може покажувач
	Shape *sl[] = { new Circle(1,2,3), new Rectangle(2,3,4,5), new Circle(0,0,1), 0 };
	int i = 0;
	while (p = sl[i++])
		p->Draw();
	for (int i = 0; sl[i]; delete sl[i++]);
	return(0);
}
