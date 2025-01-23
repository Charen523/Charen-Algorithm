#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int n, m, r;
vector<vector<int>> graph;
vector<bool> visited;
void dfs(vector<int>& answer, int v, int depth = 0) {
	visited[v] = true;
	answer[v] = depth;

	for (int i = 0; i < graph[v].size(); i++) {
		int nextV = graph[v][i];
		if (!visited[nextV]) {
			dfs(answer, nextV, depth + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> r;

	graph.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), greater<int>());
	}

	vector<int> answer(n + 1, -1);
	visited.resize(n + 1);
	dfs(answer, r);

	for (int i = 1; i <= n; i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}