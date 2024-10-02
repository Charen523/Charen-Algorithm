#include <iostream>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	int coinArr[4] = { 0 };
	for (int i = 0; i < testCase; i++) {
		int value;
		cin >> value;

		coinArr[0] = value / 25;
		value -= 25 * coinArr[0];

		coinArr[1] = value / 10;
		value -= 10 * coinArr[1];

		coinArr[2] = value / 5;
		value -= 5 * coinArr[2];

		coinArr[3] = value;

		for (int j = 0; j < 4; j++) {
			cout << coinArr[j] << ' ';
		}
		cout << endl;
	}
}