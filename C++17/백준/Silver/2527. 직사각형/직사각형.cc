#include <iostream>

using namespace std;

int main() {
	const int testCase = 4;

	for (int i = 0; i < testCase; i++) {
		int x1, y1, p1, q1;
		cin >> x1 >> y1 >> p1 >> q1;

		int x2, y2, p2, q2;
		cin >> x2 >> y2 >> p2 >> q2;

		if (p1 < x2 || x1 > p2 || y1 > q2 || q1 < y2) {
			cout << 'd' << '\n';
			continue;
		}

		if (x1 == p2 || p1 == x2) {
			if (y1 == q2 || q1 == y2) {
				cout << 'c' << '\n';
			}
			else {
				cout << 'b' << '\n';
			}
			continue;
		}

		if (y1 == q2 || q1 == y2) {
			cout << 'b' << '\n';
			continue;
		}

		cout << 'a' << '\n';
	}
}