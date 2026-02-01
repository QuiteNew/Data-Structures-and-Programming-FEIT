class BC {
public:
	int f1(int x);
	int f1(int x, float y);
	int f2(int x);
};
class DC : public BC {
public:
	int f1(int x); //se redefinira
};
int main() {
	DC d, e;
	d.f1(5); // OK call DC::f1(int)
	d.f2(4); // OK call BC::f2(int)
	e.f1(2, 3.45); // ne moze!!!
	return 0;
}
