#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector<bool> dp(n + 1);
	dp[1] = false;

	if (n >= 2)
		dp[2] = true;

	for (int i = 3; i <= n; i++) {
		dp[i] = !dp[i - 1];
	}

	if (dp[n]) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}
}