#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> cases(n + 1);
	cases[0] = 1;
	cases[1] = 1;

	for (int i = 2; i <= n; i++) {
		cases[i] = (cases[i - 1] + cases[i - 2]) % 10007;
	}
	cout << cases[n] % 10007;
}