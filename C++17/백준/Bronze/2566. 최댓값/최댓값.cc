#include <iostream>

using namespace std;

int main() {
	int x = 1, y = 1;
	int max = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int value;
			cin >> value;
			if (value > max) {
				max = value;
				x = i + 1; y = j + 1;
			}
		}
	}

	cout << max << '\n' << x << ' ' << y << '\n';
}