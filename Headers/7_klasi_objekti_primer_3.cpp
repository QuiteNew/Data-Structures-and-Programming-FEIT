#include <iostream>
using std::cout;
using std::endl;
class Time {
public:
	Time();
	void setTime(int, int, int);
	void printMilitary();
	void printStandard();
private:
	int cas;   // 0 – 23
	int min;   // 0 – 59
	int sec;   // 0 – 59
};
Time::Time() { cas = min = sec = 0; }

void Time::setTime(int h, int m, int s) {
	cas = (h >= 0 && h < 24) ? h : 0;
	min = (m >= 0 && m < 60) ? m : 0;
	sec = (s >= 0 && s < 60) ? s : 0;
}
void Time::printMilitary() {
	cout << (cas < 10 ? "0" : "") << cas << ":"  << ( min < 10 ? "0" : "" ) << min << endl; 
}
void Time::printStandard() {
	cout << ((cas == 0 || cas == 12) ? 12 : cas % 12)
		<< ":" << (min< 10 ? "0" : "") << min
		<< ":" << (sec < 10 ? "0" : "") << sec
		<< (cas < 12 ? " AM" : " PM") << endl;
}

int main() {
	Time t;
	cout << "The initial military time is ";  t.printMilitary();
	cout << "\nThe initial standard time is ";  t.printStandard();
	t.setTime(13, 27, 6);
	cout << "\n\nMilitary time after setTime is ";  t.printMilitary();
	cout << "\nStandard time after setTime is ";
	t.printStandard();
	t.setTime(99, 99, 99);
	cout << "\n\nAfter attempting invalid settings:"  << "\nMilitary time : "; 
	t.printMilitary();
	cout << "\nStandard time: ";
	t.printStandard();
	cout << endl;
	return 0;
}


