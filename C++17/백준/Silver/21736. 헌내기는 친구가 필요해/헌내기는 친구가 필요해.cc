#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs(vector<vector<char>> g, pair<int, int> s, int& r) {
	int n = g.size(); int m = g[0].size();
	vector<vector<bool>> isVisited(n, vector<bool>(m, false));
	stack<pair<int, int>> nodes;

	nodes.push(s);
	isVisited[s.first][s.second];

	while (!nodes.empty()) {
		pair<int, int> temp = nodes.top();
		nodes.pop();
		for (int i = 0; i < dir.size(); i++) {
			pair<int, int> next = {temp.first + dir[i].first, temp.second + dir[i].second};
			if (next.first < 0 || next.first >= n) continue; 
			if (next.second < 0 || next.second >= m) continue;
			if (isVisited[next.first][next.second]) continue;
			isVisited[next.first][next.second] = true;
			switch(g[next.first][next.second]) {
				case 'P':
				r++;
				case 'O':
				nodes.push(next);
				break;
				default:
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	pair<int, int> start; int result = 0;
	vector<vector<char>> graph(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			graph[i][j] = s[j];

			if (s[j] == 'I') {
				start = {i, j};
			}
		}
	}

	bfs(graph, start, result);

	if (result == 0) {
		cout << "TT";
	}
	else cout << result;
	return 0;
}