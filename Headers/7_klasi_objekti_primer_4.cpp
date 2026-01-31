#include <iostream>
using std::cout;
using std::endl;
class Time {
public:
	Time(int = 0, int = 0, int = 0);
	~Time();
	void setTime(int, int, int);
	void printMilitary();
	void printStandard();
private:
	int cas;   // 0 – 23
	int min;   // 0 – 59
	int sec;   // 0 – 59
};

Time::Time(int c, int m, int s) { cas = c; min = m; sec = s; }
Time::~Time() {}
void Time::setTime(int h, int m, int s) {
	cas = (h >= 0 && h < 24) ? h : 0;
	min = (m >= 0 && m < 60) ? m : 0;
	sec = (s >= 0 && s < 60) ? s : 0;
}
void Time::printMilitary() {
	cout << '\t' << (cas < 10 ? "0" : "") << cas << " : " << (min < 10 ? "0" : "") << min << endl;
}
void Time::printStandard() {
	cout << '\t' << ((cas == 0 || cas == 12) ? 12 : cas % 12)
		<< ":" << (min < 10 ? "0" : "") << min << ":"
		<< (sec < 10 ? "0" : "") << sec << (cas < 12 ? " AM" : " PM") << endl;
}

int main() {
	Time t1, t2(2), t3(21, 34), t4(12, 25, 42), t5(27, 74, 99);
	cout << "Povikan konstruktor\n"; 
	cout << "Bez argumenti\n"; t1.printMilitary(); t1.printStandard();
	cout << "So eden argument\n"; t2.printMilitary(); t2.printStandard();
	cout << "So dva argumenti\n"; t3.printMilitary(); t3.printStandard();
	cout << "So tri argimenti\n"; t4.printMilitary(); t4.printStandard();
	cout << "so pogresni vrednosti\n"; 
	t5.printMilitary(); t5.printStandard();
	cout << endl;
	return 0;
}


