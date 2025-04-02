#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int n; cin >> n;
	vector<int> chains(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> chains[i] >> chains[i + 1];
	}

	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			dp[i][j] = 1e9;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j],
				dp[i][k] + dp[k + 1][j] + chains[i] * chains[k + 1] * chains[j + 1]);
			}
		}		
	}
    
	cout << dp[0][n - 1];

	return 0;
}