#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_dist = 0;
int far_node = 0;

void dfs(const vector<vector<pair<int, int>>>& tree, int node, int dist, vector<bool>& visited) {
    visited[node] = true;

    if (dist > max_dist) {
        max_dist = dist;
        far_node = node;
    }

    for (auto [next, weight] : tree[node]) {
        if (!visited[next]) {
            dfs(tree, next, dist + weight, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({ b, c });
        tree[b].push_back({ a, c });
    }

    vector<bool> visited(n + 1, false);
    dfs(tree, 1, 0, visited);

    fill(visited.begin(), visited.end(), false);
    max_dist = 0;
    dfs(tree, far_node, 0, visited);

    cout << max_dist << '\n';
    return 0;
}