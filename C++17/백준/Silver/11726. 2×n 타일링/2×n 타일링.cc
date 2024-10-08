#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n;
	cin >> n;

	vector<long long> cases(n + 1);
	cases[0] = 1;
	cases[1] = 1;

	for (int i = 2; i <= n; i++) {
		cases[i] = (cases[i - 1] + cases[i - 2]) % 10007;
	}
	cout << cases[n] % 10007;
}