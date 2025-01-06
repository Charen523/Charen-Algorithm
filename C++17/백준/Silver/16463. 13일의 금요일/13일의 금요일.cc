#include <iostream>

using namespace std;

constexpr int MONTH = 12;
const int DAY[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
constexpr int LEAPFEB = 29;

bool isLeapYear(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			return year % 400 == 0;
		}
		return true; 
	}
	return false; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int year;
	cin >> year;

	int result = 0;
	int curDay = 4; //2019년 1월 3일 = 금요일.
	for (int y = 2019; y <= year; y++) {
		int curMonth = 0;
		while (curMonth < MONTH) {
			curDay += 7;
			if (curDay == 13) {
				result++;
			}
			else if (curDay > DAY[curMonth]) {
				if (curMonth == 1 && isLeapYear(y)) curDay -= LEAPFEB;
				else curDay -= DAY[curMonth];
				curMonth++;
			}
		}
	}
	cout << result;
}