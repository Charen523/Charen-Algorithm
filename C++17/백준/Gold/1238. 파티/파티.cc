#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<int> dijkstra(const vector<vector<int>>& mat, int start) {
    int n = mat.size();
    vector<int> dist(n, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (int v = 0; v < n; v++) {
            if (mat[u][v] == 0) continue;
            int nd = d + mat[u][v];
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;
    x--;

    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> rmat(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int s,e,t; cin >> s >> e >> t;
        s--; e--;
        mat[s][e] = t;
        rmat[e][s] = t; // 역방향
    }

    vector<int> out = dijkstra(mat, x);   // X -> i
    vector<int> in  = dijkstra(rmat, x);  // i -> X

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] == INF || out[i] == INF) continue;
        ans = max(ans, in[i] + out[i]);
    }
    cout << ans << '\n';
    return 0;
}
