#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> Graph;

void dfs(const Graph& g, const int s) {
	stack<int> arr;
	vector<bool> isVisited(g.size());

	arr.push(s);

	while (!arr.empty()) {
		int curr = arr.top(); arr.pop();

		if (isVisited[curr]) continue;

		cout << curr << ' ';
		isVisited[curr] = true;

		for (int i = g[curr].size() - 1; i >= 0; i--) {
			int next = g[curr][i];
			if (!isVisited[next]) {
				arr.push(next);
			}
		}
	}
}

void bfs(const Graph& g, const int s) {
	queue<int> q;
	vector<bool> isVisited(g.size());

	q.push(s);
	cout << s << ' ';
	isVisited[s] = true;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (int i = 0; i < g[temp].size(); i++) {
			int next = g[temp][i];
			if (!isVisited[next]) {
				q.push(next);
				cout << next << ' ';
				isVisited[next] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, v;
	cin >> n >> m >> v;
	Graph g(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end());
	}

	dfs(g, v);
	cout << '\n';
	bfs(g, v);

	return 0;
}