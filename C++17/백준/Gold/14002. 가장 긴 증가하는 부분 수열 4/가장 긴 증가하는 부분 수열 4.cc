#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> dp(n, 1);      // 각 위치에서의 LIS 길이
	vector<int> prev(n, -1);   // LIS 경로 추적용

	int max_len = 1;
	int max_idx = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
		if (dp[i] > max_len) {
			max_len = dp[i];
			max_idx = i;
		}
	}

	cout << max_len << '\n';

	stack<int> result;
	int idx = max_idx;
	while (idx != -1) {
		result.push(v[idx]);
		idx = prev[idx];
	}

	while (!result.empty()) {
		cout << result.top() << ' ';
		result.pop();
	}

	return 0;
}