#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
    }

    int startCity, endCity;
    cin >> startCity >> endCity;

    const long long INF = (1LL << 60);
    vector<long long> dist(N + 1, INF);
    vector<bool> visited(N + 1, false);

    dist[startCity] = 0;

    for (int iter = 1; iter <= N; iter++) {
        int u = -1;
        long long best = INF;

        // 방문하지 않은 정점 중 dist 최소 찾기
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && dist[i] < best) {
                best = dist[i];
                u = i;
            }
        }

        // 더 이상 도달 가능한 정점 없음
        if (u == -1) break;

        visited[u] = true;
        if (u == endCity) break; // endCity 최단거리 확정

        // relax
        for (auto [v, w] : graph[u]) {
            if (visited[v]) continue;
            long long nd = dist[u] + (long long)w;
            if (nd < dist[v]) dist[v] = nd;
        }
    }

    cout << dist[endCity];
    return 0;
}