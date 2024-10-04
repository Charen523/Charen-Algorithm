#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	const int helper = 2 + N;
	cout << (N * (N + 1) / 2) * helper << '\n';
}