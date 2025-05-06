#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int SIZE = 9;
const int MAX_SLOT = 45;

struct Point {
	int x;
	int y;
};

void find_numbers(const vector<vector<int>>& m, int x, int y, vector<bool>& used) {
	for (int i = 0; i < SIZE; i++) {
		if (m[i][y] != 0) used[m[i][y]] = true;
		if (m[x][i] != 0) used[m[x][i]] = true;
	}

	x = x / 3 * 3;
	y = y / 3 * 3;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (m[i][j] != 0) used[m[i][j]] = true;
		}
	}
}

bool back_tracking(vector<vector<int>>& board, const vector<Point>& slots, int idx) {
	if (idx == slots.size()) return true;

	Point p = slots[idx];
	vector<bool> used(10, false);

	find_numbers(board, p.x, p.y, used);

	for (int num = 1; num <= SIZE; num++) {
		if (used[num]) continue;

		board[p.x][p.y] = num;
		if (back_tracking(board, slots, idx + 1)) return true;
		board[p.x][p.y] = 0; // 되돌리기
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> matrix(SIZE, vector<int>(SIZE));
	vector<Point> slots;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 0) {
				slots.push_back({ i, j });
			}
		}
	}

	back_tracking(matrix, slots, 0);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}