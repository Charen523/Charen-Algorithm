#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(vector<vector<int>>& v, int x, int y) {
	int n = v.size();
	

	int result = 1;
	queue<pair<int, int>> q;
	q.push({x, y});
	v[x][y] = 0; 

	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();

		for (int i = 0; i < dir.size(); i++) {
			int _x = temp.first + dir[i].first;
			int _y = temp.second + dir[i].second;
			if (_x >= 0 && _x < n && _y >= 0 && _y < n) {
				if (v[_x][_y] == 1) {
					v[_x][_y] = 0;
					result++;
					q.push({_x, _y});
				}
			}
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			v[i][j] = s[j] - '0';
		}
	}

	vector<int> towns;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1) {
				towns.push_back(bfs(v, i, j));
			}
		}
	}

	sort(towns.begin(), towns.end());
	cout << towns.size() << '\n';
	for (int i : towns) {
		cout << i << '\n';
	}

	return 0;
}