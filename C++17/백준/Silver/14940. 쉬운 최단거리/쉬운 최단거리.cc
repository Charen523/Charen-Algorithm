#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int type;
	int result;

	Node() : type(1), result(-1) {}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int rowCount, colCount;
	cin >> rowCount >> colCount;

	vector<vector<Node>> map(rowCount, vector<Node>(colCount));
	int desX = 0, desY = 0;
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			int type;
			cin >> type;
			
			if (type == 0) {
				map[i][j].type = 0;
				map[i][j].result = 0;
			}
			else if (type == 2) {
				map[i][j].type = 2;
				map[i][j].result = 0;
				desX = i;
				desY = j;
			}
		}
	}

	queue<pair<int, int>> curMove;
	
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	for (int dir = 0; dir < 4; dir++) {
		int newX = desX + dx[dir];
		int newY = desY + dy[dir];

		if (newX >= 0 && newX < rowCount && newY >= 0 && newY < colCount && map[newX][newY].type == 1) {
			map[newX][newY].type = -1;
			map[newX][newY].result = 1;
			curMove.push({ newX, newY });
		}
	}

	int step = 1;

	while (!curMove.empty()) {
		step++;
		int curSize = curMove.size();

		for (int i = 0; i < curSize; i++) {
			auto [x, y] = curMove.front();
			curMove.pop();

			for (int dir = 0; dir < 4; dir++) {
				int newX = x + dx[dir];
				int newY = y + dy[dir];

				if (newX >= 0 && newX < rowCount && newY >= 0 && newY < colCount && map[newX][newY].type == 1) {
					map[newX][newY].type = -1;
					map[newX][newY].result = step;
					curMove.push({ newX, newY });
				}
			}
		}
	}

	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			cout << map[i][j].result << ' ';
		}
		cout << '\n';
	}
}