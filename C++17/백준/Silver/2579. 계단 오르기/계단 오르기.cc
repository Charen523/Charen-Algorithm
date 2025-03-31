#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int n; cin >> n;
	vector<int> stairs(n);
	for (int i = 0; i < n; i++) {
		cin >> stairs[i];
	}
    
	vector<int> dp(n);
	dp[0] = stairs[0];
	
	if (n < 2) {
		cout << dp[0];
		return 0;
	}
	dp[1] = stairs[0] + stairs[1];
	
	if (n < 3) {
		cout << dp[1];
		return 0;
	}
	dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (int i = 3; i < n; i++) {
		//한 칸 건너뛰기
		int case1 = dp[i - 2] + stairs[i];
		//연속으로 2칸
		int case2 = dp[i - 3] + stairs[i - 1] + stairs[i];
		dp[i] = max(case1, case2);
	}

	cout << dp[n - 1];

	return 0;
}