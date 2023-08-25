//Create class Time which contains :
//-hour(int)
//- min(int)
//- sec(int)
//- Default & parameterized constructors
//- Setters & getters for each attribute
//- Overload++ (prefix operator) which increase seconds by 1 .
//o You should handle all cases correctly, E.g. :
//o If time is(23:59 : 59) it will be(0, 0, 0)
//- Overload-- (prefix operator) which decrease seconds by 1 .
//o You should handle all cases correctly, E.g. :
//    o If time is(0, 0, 0) it will be(23:59 : 59)
//    - Overload << to print Time as following format :
//o Hour : min:sec
//o E.g. 10 : 55 : 30
#include <iostream>
using namespace std;

class Time {
private:
	int hour, min, sec;
public:
	Time() {
		hour = 0;
		min = 0;
		sec = 0;
	}
	Time(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}
	void set_time(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}
	int get_h() { return hour; }
	int get_m() { return min; }
	int get_s() { return sec; }
	void operator++() {
		if (sec < 59) { sec++; }
		else {
			sec = 0;
			if (min < 59) { min++; }
			else {
				min = 0;
				if (hour < 23) {
					hour++;
				}
				else {
					hour = 0;
				}
			}
		}

	}
	void operator--() {
		if (sec > 0) { sec--; }
		else {
			sec = 59;
			if (min > 0) { min--; }
			else {
				min = 59;
				if (hour > 0) {
					hour++;
				}
				else {
					hour = 23;
				}
			}
		}

	}
	//void print() {
	//	cout << hour << ":" << min << ":" << sec << endl;
	//}
};
ostream& operator<<(ostream& time, Time t) {
	return time << t.get_h() << ":" << t.get_m() << ":" << t.get_s() << endl;
}

int main()
{
	Time t(0, 0, 0);
	--t;
	cout << t;
	++t;
	cout << t;
}