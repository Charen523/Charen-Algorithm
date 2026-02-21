#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;

ull a_count = 0;
ull b_count = 0;

void fib(ull n) {
	ull prev1 = 1, prev2 = 1, cur;
	for (int i = 3; i <= n; i++) {
		cur = (prev2 + prev1) % 1000000007;
		prev2 = prev1;
		prev1 = cur;
	}
	a_count = cur;
	b_count = n - 2;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ull n;  // 5 <= n <= 2 * 10^8
	cin >> n; //input.

	fib(n);

	cout << a_count;
	cout << ' ';
	cout << b_count % 1000000007;

	return 0;
}