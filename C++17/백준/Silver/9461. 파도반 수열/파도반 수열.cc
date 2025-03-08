#include <iostream>
#include <vector>

using namespace std;

int idx = 4;

void solve(vector<long long>& dp, int n) {
	for (idx; idx <= n; idx++) {
		dp[idx] = dp[idx - 2] + dp[idx - 3];
	}

	cout << dp[n] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	

	int t; //test case 개수
	cin >> t;

	vector<long long> dp(101, 1);

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		solve(dp, n);
	}

	return 0;
}