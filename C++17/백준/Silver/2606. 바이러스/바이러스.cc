#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& adjList, vector<bool>& visited, int& nodeCount){
	visited[node] = true;
	nodeCount++;

	for (int neighbor : adjList[node]) {
		if (!visited[neighbor])
			dfs(neighbor, adjList, visited, nodeCount);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int totalNodes, linkCount;
	cin >> totalNodes >> linkCount;

	vector<vector<int>> adjList(totalNodes + 1);
	vector<bool> visited(totalNodes + 1, false);

	for (int i = 0; i < linkCount; i++) {
		int start, end;
		cin >> start >> end;
		adjList[start].push_back(end);
		adjList[end].push_back(start);
	}

	int nodeCount = 0;
	dfs(1, adjList, visited, nodeCount);
	cout << nodeCount - 1;
}