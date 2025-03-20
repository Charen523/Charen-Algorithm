#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

typedef vector<vector<pair<int, int>>> Graph;

void dijkstra(const Graph& g, vector<int>& ans, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    ans[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cur_weight = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        // 현재 노드에서 연결된 모든 간선을 확인
        for (const auto& [next, weight] : g[cur]) {
            int new_weight = cur_weight + weight;
            if (new_weight < ans[next]) {
                ans[next] = new_weight;
                pq.push({ new_weight, next });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e;
    cin >> v >> e;

    int startPoint;
    cin >> startPoint;

    Graph graph(v);
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({ v - 1, w });
    }

    vector<int> answer(v, INT_MAX);
    dijkstra(graph, answer, startPoint - 1);

    for (int a : answer) {
        if (a == INT_MAX)
            cout << "INF";
        else
            cout << a;
        cout << '\n';
    }

    return 0;
}