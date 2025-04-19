#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int M, N, H;
	cin >> M >> N >> H;

	vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
	queue<tuple<int, int, int>> q;

	for (int h = 0; h < H; h++) {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				cin >> box[h][r][c];
				if (box[h][r][c] == 1) {
					q.push({ h, r, c });
				}
			}
		}
	}

	while (!q.empty()) {
		auto [z, x, y] = q.front(); q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nz >= 0 && nz < H && nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (box[nz][nx][ny] == 0) {
					box[nz][nx][ny] = box[z][x][y] + 1;
					q.push({ nz, nx, ny });
				}
			}
		}
	}

	int maxDay = 0;
	for (int h = 0; h < H; h++) {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (box[h][r][c] == 0) {
					cout << -1;
					return 0;
				}
				maxDay = max(maxDay, box[h][r][c]);
			}
		}
	}

	cout << maxDay - 1;
	return 0;
}

