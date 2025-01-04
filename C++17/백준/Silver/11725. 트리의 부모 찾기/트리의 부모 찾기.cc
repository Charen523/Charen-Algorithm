#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void findParents(int parValue, vector<int>& answer, vector<vector<int>>& graph, vector<bool>& visited) {
	visited[parValue] = true;

	for (int child : graph[parValue]) {
		if (!visited[child]) { 
			answer[child] = parValue; 
			findParents(child, answer, graph, visited); 
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> answer(n + 1);
	vector<bool> visited(n + 1, false);
	findParents(1, answer, graph, visited);

	for (int i = 2; i <= n; i++) {
		cout << answer[i] << '\n';
	}
}