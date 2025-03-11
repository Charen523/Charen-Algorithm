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
	vector<vector<int>> dp(3, vector<int>(2));
	for (int i = 1; i <= n; i++) {
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
		int idx = i % 3;
		if (dp[(i - 1) % 3][1] == 2) { //다음잔=빼고 집기.
			int A = dp[(i - 1) % 3][0];
			int B = dp[(i -2) % 3][0] + red_wine[i];
			int C = dp[idx][0] + red_wine[i - 1] + red_wine[i];

			if (A < B) {
				if (B < C) {
					dp[idx][0] = C;
					dp[idx][1] = 2;
				}
				else {
					dp[idx][0] = B;
					dp[idx][1] = 1;
				}
			}
			else {
				if (A < C) {
					dp[idx][0] = C;
					dp[idx][1] = 2;
				}
				else {
					dp[idx][0] = A;
					dp[idx][1] = 0;
				}
			}
		}
		else {
			dp[idx][0] = dp[(i - 1) % 3][0] + red_wine[i];
			dp[idx][1] = dp[(i - 1) % 3][1] + 1;
		}
	}

	cout << dp[n % 3][0];

	return 0;
}