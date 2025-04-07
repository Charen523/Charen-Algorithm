#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // 입력: 가중치 인접 행렬
    vector<vector<int>> weight(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }
    }

    int result = INF;
    int allVisited = (1 << n) - 1;

    for (int start = 0; start < n; ++start) {
        // dp[current][visited]: start에서 시작해서 current에 있으며 visited 상태일 때 최소 비용
        vector<vector<int>> dp(n, vector<int>(1 << n, INF));
        dp[start][1 << start] = 0;

        for (int visited = 0; visited < (1 << n); ++visited) {
            for (int current = 0; current < n; ++current) {
                if (!(visited & (1 << current))) continue;
                if (dp[current][visited] == INF) continue;

                for (int next = 0; next < n; ++next) {
                    if (visited & (1 << next)) continue;
                    if (weight[current][next] == 0) continue;

                    int nextVisited = visited | (1 << next);
                    dp[next][nextVisited] = min(dp[next][nextVisited],
                                                dp[current][visited] + weight[current][next]);
                }
            }
        }

        // 모든 도시 방문 후 start로 복귀
        for (int last = 0; last < n; ++last) {
            if (last == start) continue;
            if (dp[last][allVisited] == INF) continue;
            if (weight[last][start] == 0) continue;

            result = min(result, dp[last][allVisited] + weight[last][start]);
        }
    }

    cout << result << '\n';
    return 0;
}