#include <iostream>
#include <vector>
#include <queue>
#include <limits>
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

    // (거리, 정점) 최소 힙
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> pq;

    dist[startCity] = 0;
    pq.push({0, startCity});

    while (!pq.empty()) {
        auto [curDist, u] = pq.top();
        pq.pop();

        // 이미 더 좋은 값으로 처리된 적 있으면 스킵
        if (curDist != dist[u]) continue;

        if (u == endCity) break; // 도착 최단거리 확정 (원하면 제거 가능)

        for (auto [v, w] : graph[u]) {
            long long nd = curDist + (long long)w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    cout << dist[endCity];
    return 0;
}