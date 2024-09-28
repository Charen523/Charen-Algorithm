#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int first = 0, second = 1;

	int result = 1;
	for (int i = 1; i < n; i++) {
		result = first + second;
		first = second;
		second = result;
	}

	cout << result << '\n';
}