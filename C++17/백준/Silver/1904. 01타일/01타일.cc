#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[1000001];
int solve(int n) {
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		//현 단계 = 전배열 + 1 or 전전배열 + 00.
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746; 
	}

	return dp[n]; //반환
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	

	int n;
	cin >> n;
	cout << solve(n);

	return 0;
}