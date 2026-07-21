#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<bool>> pool_map(n, vector<bool>(m, false));
    vector<vector<int>> dp(n, vector<int>(m, 1));

    int row_zero_idx = m;
    int col_zero_idx = n;

    for (const vector<int>& puddle : puddles) {
        int col = puddle[0] - 1;
        int row = puddle[1] - 1;

        pool_map[row][col] = true;

        if (row == 0) {
            row_zero_idx = min(row_zero_idx, col);
        }

        if (col == 0) {
            col_zero_idx = min(col_zero_idx, row);
        }
    }

    for (int col = row_zero_idx; col < m; col++) {
        dp[0][col] = 0;
    }

    for (int row = col_zero_idx; row < n; row++) {
        dp[row][0] = 0;
    }

    for (int row = 1; row < n; row++) {
        for (int col = 1; col < m; col++) {
            if (pool_map[row][col]) {
                dp[row][col] = 0;
            }
            else {
                dp[row][col] =
                    (dp[row - 1][col] + dp[row][col - 1]) % MOD;
            }
        }
    }

    return dp[n - 1][m - 1];
}