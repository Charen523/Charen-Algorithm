#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void bfs(vector<vector<int>>& box, vector<pair<int, int>>& startPoint) {
	queue<pair<int, int>> q;
	int row = box.size();
	int col = box[0].size();

	for (auto point : startPoint) {
		q.push(point);
	}

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (nr >= 0 && nr < row && nc >= 0 && nc < col) {
				if (box[nr][nc] == 0) {
					box[nr][nc] = box[r][c] + 1;
					q.push({ nr, nc });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int row, column;
	cin >> column >> row;

	vector<vector<int>> box(row, vector<int>(column));
	vector<pair<int, int>> startPoint;
	bool isMature = true;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			int value; cin >> value;
			box[i][j] = value;

			if (isMature && value == 0) isMature = false;
			if (value == 1) startPoint.push_back({ i, j });
		}
	}

	if (isMature) {
		cout << 0;
		return 0;
	}

	bfs(box, startPoint);

	int maxDays = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (box[i][j] > maxDays) {
				maxDays = box[i][j];
			}
		}
	}
	cout << maxDays - 1;
}