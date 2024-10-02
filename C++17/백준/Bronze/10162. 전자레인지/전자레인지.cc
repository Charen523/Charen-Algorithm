#include <iostream>

using namespace std;

int main() {
	int time;
	cin >> time;
	if (time % 10 != 0) {
		cout << -1; return 0;
	}

	int rangeBtn[3] = { 300, 60, 10 };
	cout << time / rangeBtn[0] << ' ';
	time %= rangeBtn[0];

	cout << time / rangeBtn[1] << ' ';
	time %= rangeBtn[1];

	cout << time / rangeBtn[2];

	return 0;
}