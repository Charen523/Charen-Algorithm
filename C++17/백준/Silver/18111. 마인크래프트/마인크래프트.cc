#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, b;

int getTime(const vector<vector<int>>& v, int h) {
	int block = b;
	int time = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int height = v[i][j];
			if (height > h) {
				time += (height - h) * 2; // 제거
				block += (height - h);
			}
			else if (height < h) {
				time += (h - height); // 추가
				block -= (h - height);
			}
		}
	}

	if (block < 0) return -1;
	return time;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> b;
	vector<vector<int>> ground(n, vector<int>(m));

	int minH = 256, maxH = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
			minH = min(minH, ground[i][j]);
			maxH = max(maxH, ground[i][j]);
		}
	}

	int resultTime = 1e9;
	int resultHeight = 0;

	for (int h = minH; h <= maxH; h++) {
		int t = getTime(ground, h);
		if (t == -1) continue;

		if (t <= resultTime) {
			resultTime = t;
			resultHeight = h;
		}
	}

	cout << resultTime << ' ' << resultHeight << '\n';
	return 0;
}
