#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> friendGraph(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (find(friendGraph[x].begin(), friendGraph[x].end(), y) != friendGraph[x].end()) continue;
		friendGraph[x].push_back(y);
		friendGraph[y].push_back(x);
	}

	vector<int> bacon(n + 1);
	for (int i = 1; i <= n; i++) {
		vector<int> lengths(n + 1, -1);
		lengths[0] = 0;

		queue<int> vertices;
		vertices.push(i);

		int distance = 0;
		while (!vertices.empty()) {
			int queueSize = vertices.size();
			for (int j = 0; j < queueSize; j++) {
				int curVertex = vertices.front();
				lengths[curVertex] = distance;

				for (int k : friendGraph[curVertex]) {
					if (lengths[k] == -1) {
						vertices.push(k);
						lengths[k]++;
					}
				}
				vertices.pop();
			}
			distance++;
		}

		bacon[i] = accumulate(lengths.begin(), lengths.end(), 0);
	}

	int min = 1;
	for (int i = 2; i <= n; i++) {
		if (bacon[i] < bacon[min]) {
			min = i;
		}
	}
	cout << min;

	return 0;
}