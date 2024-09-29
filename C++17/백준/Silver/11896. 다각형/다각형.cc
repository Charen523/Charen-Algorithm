#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	if (a < 4) a = 4;
	if (b < 4) {
		cout << 0;
		return 0;
	}

	long long a2 = ((a + 1) / 2) * 2;
	long long b2 = (b / 2) * 2;

	long long n = (b2 - a2) / 2 + 1;

	cout << (a2 + b2) * n / 2;
}