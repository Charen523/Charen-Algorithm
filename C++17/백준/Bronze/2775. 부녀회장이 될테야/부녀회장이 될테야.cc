#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int k, n;
        cin >> k >> n;

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        // 0층 초기화
        for (int i = 1; i <= n; ++i) {
            dp[0][i] = i;
        }

        // dp 채우기
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }

        cout << dp[k][n] << '\n';
    }

    return 0;
}
