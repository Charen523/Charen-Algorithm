#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 10007;

int solve(int n, int k) {
    vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j >= 1; j--) {
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    }
    return dp[k];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (k > (n + 1) / 2) k = n - k;
	cout << solve(n, k);

	return 0;
}