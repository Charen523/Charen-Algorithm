#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int index;
	cin >> index;

	long long first = 0;
	long long second = 1;

	switch (index) {
	case 1:
		cout << second << '\n';
		break;
	default:
		long long result = 0;
		for (int i = 0; i < index - 1; i++) {
			result = first + second;
			first = second;
			second = result;
		}
		cout << result << '\n';
	}
}