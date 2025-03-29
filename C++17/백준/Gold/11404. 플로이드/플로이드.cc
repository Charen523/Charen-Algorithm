#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i)
        g[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int start, end, price;
        cin >> start >> end >> price;
        --start; --end;
        g[start][end] = min(g[start][end], price);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][k] < INF && g[k][j] < INF)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << g[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}