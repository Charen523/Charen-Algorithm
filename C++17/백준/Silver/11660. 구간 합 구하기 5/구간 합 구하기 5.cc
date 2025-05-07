#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; 
	cin >> n >> m;

	vector<vector<int>> table(n + 1, vector<int>(n + 1));
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));

	// 입력 (1-based index로 맞춰 저장)
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> table[i][j];
		}
	}

	// 누적합 dp 테이블 생성
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + table[i][j];
		}
	}

	// 질의 처리
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int sum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << sum << '\n';
	}

	return 0;
}
