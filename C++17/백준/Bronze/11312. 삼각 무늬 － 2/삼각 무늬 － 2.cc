#include <iostream>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		long long A, B;
		cin >> A >> B;
		cout << (A / B) * (A / B) << '\n';
	}
}