#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void flipNear(vector<vector<bool>>& matrix, int x, int y) {
	int rows = matrix.size();
	int cols = matrix[0].size();

	queue< pair<int, int>> q;
	q.push({ x, y });
	matrix[x][y] = false;

	while (!q.empty()) {
		pair<int, int> curSlot = q.front();
		q.pop();

		if (curSlot.first - 1 >= 0 && matrix[curSlot.first - 1][curSlot.second]) {
			matrix[curSlot.first - 1][curSlot.second] = false;
			q.push({ curSlot.first - 1, curSlot.second });
		}
		if (curSlot.first + 1 < rows && matrix[curSlot.first + 1][curSlot.second]) {
			matrix[curSlot.first + 1][curSlot.second] = false;
			q.push({ curSlot.first + 1, curSlot.second });
		}
		if (curSlot.second - 1 >= 0 && matrix[curSlot.first][curSlot.second - 1]) {
			matrix[curSlot.first][curSlot.second - 1] = false;
			q.push({ curSlot.first, curSlot.second - 1 });
		}
		if (curSlot.second + 1 < cols && matrix[curSlot.first][curSlot.second + 1]) {
			matrix[curSlot.first][curSlot.second + 1] = false;
			q.push({ curSlot.first, curSlot.second + 1 });
		}
	}
}

int main() {
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int row, col, cabbageCount;
		cin >> row >> col >> cabbageCount;
		
		vector<vector<bool>> matrix(row, vector<bool>(col, false));
		for (int i = 0; i < cabbageCount; i++) {
			int r, c;
			cin >> r >> c;
			matrix[r][c] = true;
		}

		int result = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (matrix[i][j]) {
					result++;
					flipNear(matrix, i, j);
				}
			}
		}
		cout << result << '\n';
	}
}