#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<vector<int>> cost(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2]; // r, g, b
	}

	int answer = INF;

	for (int first = 0; first < 3; first++) {
		vector<vector<int>> dp(n, vector<int>(3, INF));
		dp[0][first] = cost[0][first];

		for (int i = 1; i < n; i++) {
			dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}

		// 마지막 집은 first와 다른 색만 허용
		for (int last = 0; last < 3; last++) {
			if (last == first) continue;
			answer = min(answer, dp[n - 1][last]);
		}
	}

	cout << answer << '\n';
	return 0;
}
