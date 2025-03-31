#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);
	
	int n; cin >> n;

	vector<int> dp(n);
	dp[0] = 1;
	if (n < 2) {
		cout << dp[0]; return 0;
	}
	dp[1] = 3;

	for (int i = 2; i < n; i++) {
		dp[i] = dp[i - 1];
		dp[i] += dp[i - 2] * 2;
		dp[i] %= 10007;
	}

	cout << dp[n - 1];

	return 0;
}