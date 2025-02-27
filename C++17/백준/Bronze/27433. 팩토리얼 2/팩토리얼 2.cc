#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	long long result = 1;
	for (int i = 1; i <= N; i++) {
		result *= i;
	}

	cout << result;
}