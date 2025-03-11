#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);
    
	int n;
	cin >> n;

	vector<int> red_wine(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(2));
	for (int i = 1; i < n + 1; i++) {
		cin >> red_wine[i];
	}

	dp[0][0] = 0;
	dp[0][1] = 0;

	dp[1][0] = red_wine[1];
	dp[1][1] = 1;

	if (n > 1) {
		dp[2][0] = red_wine[1] + red_wine[2];
		dp[2][1] = 2;
	}

	for (int i = 3; i <= n; i++) {
		if (dp[i - 1][1] == 2) { //다음잔=빼고 집기.
			int A = dp[i - 1][0];
			int B = dp[i - 2][0] + red_wine[i];
			int C = dp[i - 3][0] + red_wine[i - 1] + red_wine[i];

			if (A < B) {
				if (B < C) {
					dp[i][0] = C;
					dp[i][1] = 2;
				}
				else {
					dp[i][0] = B;
					dp[i][1] = 1;
				}
			}
			else {
				if (A < C) {
					dp[i][0] = C;
					dp[i][1] = 2;
				}
				else {
					dp[i][0] = A;
					dp[i][1] = 0;
				}
			}
		}
		else {
			dp[i][0] = dp[i - 1][0] + red_wine[i];
			dp[i][1] = dp[i - 1][1] + 1;
		}
	}

	cout << dp[n][0];

	return 0;
}