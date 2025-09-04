#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<pair<int, int>> direction{ {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

bool isValid(int n, int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) {
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int normal = 0, weak = 0;
	vector<vector<bool>> isVisited(n, vector<bool>(n));

	//normal count
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!isVisited[i][j]) {
				char tempColor = v[i][j];
				if (v[i][j] == 'G') v[i][j] = 'R';
				normal++;
				queue<pair<int, int>> q;
				q.push({ i, j });
				isVisited[i][j] = true;

				//bfs
				while (!q.empty()) {
					pair<int, int> temp = q.front();
					q.pop();

					for (auto d : direction) {
						int x = temp.first + d.first;
						int y = temp.second + d.second;
						if (isValid(n, x, y) && !isVisited[x][y] && v[x][y] == tempColor) {
							isVisited[x][y] = true;
							q.push({ x, y });

							if (v[x][y] == 'G') v[x][y] = 'R';
						}
					}
				}
			}
		}
	}

	//weak count
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (isVisited[i][j]) {
				char tempColor = v[i][j];
				weak++;
				queue<pair<int, int>> q;
				q.push({ i, j });
				isVisited[i][j] = false;

				//bfs
				while (!q.empty()) {
					pair<int, int> temp = q.front();
					q.pop();

					for (auto d : direction) {
						int x = temp.first + d.first;
						int y = temp.second + d.second;
						if (isValid(n, x, y) && isVisited[x][y] && v[x][y] == tempColor) {
							isVisited[x][y] = false;
							q.push({ x, y });
						}
					}
				}
			}
		}
	}

	cout << normal << ' ' << weak << '\n';

	return 0;
}