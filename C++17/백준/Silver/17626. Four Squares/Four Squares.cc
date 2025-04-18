#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<int> dp(n + 1, 4);
	for (int i = 1; i <= n; i++) {
		int iSqrt = sqrt(i);
		if (i == iSqrt * iSqrt) dp[i] = 1;
		else {
			for (int j = 1; j <= iSqrt; j++) {
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
	}

	cout << dp[n];
	return 0;
}