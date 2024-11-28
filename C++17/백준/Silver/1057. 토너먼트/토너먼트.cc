#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b;
	cin >> n >> a >> b;

	int result = 0;
	while (a != b) {
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		result++;
	}
	cout << result;
}