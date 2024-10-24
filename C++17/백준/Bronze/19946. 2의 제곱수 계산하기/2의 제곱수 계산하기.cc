#include <iostream>
#define ull unsigned long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ull input;
	cin >> input;

	if (input == 18446744073709551615) {
		cout << 64;
		return 0;
	}

	while (input % 2 == 0) {
		input /= 2;
	}
	input++;

	int power = 0;
	while (input > 1) {
		input >>= 1;
		power++;
	}

	cout << power;
}