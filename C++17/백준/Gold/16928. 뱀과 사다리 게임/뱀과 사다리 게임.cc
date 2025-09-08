#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> jump(101);
    for (int i = 1; i <= 100; ++i) jump[i] = i;

    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        jump[x] = y;
    }
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        jump[u] = v;
    }

    vector<int> dist(101, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == 100) break;
        for (int d = 1; d <= 6; ++d) {
            int v = u + d;
            if (v > 100) break;
            v = jump[v];
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    cout << dist[100] << '\n';
    return 0;
}
