#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<int>> maze(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			maze[i][j] = s[j] - '0';
		}
	}

	vector<pair<int, int>> direction = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };

	vector<pair<int, int>> nodes;
	int result = 1;
	nodes.push_back({ 0, 0 });
	maze[0][0] = 0;
	
	while (true) {
		result++;

		vector<pair<int, int>> next;
		for (auto [x, y] : nodes) {
			for (auto [vx, vy] : direction) {
				int _x = x + vx;
				int _y = y + vy;
				if (_x == n - 1 && _y == m - 1) {
					cout << result;
					return 0;
				}
				else if (_x >= 0 && _x < n && _y >= 0 && _y < m) {
					if (maze[_x][_y] != 0) {
						next.push_back({ _x, _y });
						maze[_x][_y] = 0;
					}
				}
			}
		}
		nodes = next;
	}

	return 0;
}