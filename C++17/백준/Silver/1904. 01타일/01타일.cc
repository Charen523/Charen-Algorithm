#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solve(int n) {
	int dp[3];
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		//현 단계 = 전배열 + 1 or 전전배열 + 00.
		dp[i % 3] = (dp[(i - 1) % 3] + dp[(i - 2) % 3]) % 15746; 
	}

	return dp[n % 3]; //반환
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	

	int n;
	cin >> n;
	cout << solve(n);

	return 0;
}