#include <iostream>
#include <vector>
using namespace std;



int solve(const int target, const vector<int>& v) {
	vector<int> dp(target + 1, 0);
	dp[0] = 1;

	for (int value : v) {
		for (int i = value; i <= target; i++) {
			dp[i] += dp[i - value];
		}
	}

	return dp[target];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;

		vector<int> v(n);
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}

		int m; cin >> m;
		cout << solve(m, v);
		cout << '\n';
	}

	return 0;
}