#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int check(int num, const vector<bool>& btns) {
	if (num == 0) return btns[0] ? 1 : -1;
	int len = 0;
	while (num > 0) {
		if (!btns[num % 10]) return -1;
		len++;
		num /= 10;
	}
	return len;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<bool> btns(10, true);
	for (int i = 0; i < m; i++) {
		int b;
		cin >> b;
		btns[b] = false;
	}

	int result = abs(n - 100);

	for (int i = 0; i <= 999999; i++) {
		int len = check(i, btns);
		if (len != -1) {
			int press = len + abs(i - n);
			if (press < result) result = press;
		}
	}

	cout << result;
	return 0;
}