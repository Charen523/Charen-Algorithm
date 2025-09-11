#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int board[505][505];
bool visited[505][505];
vector<pair<int, int>> direction = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
int maxValue, maxCell;

inline bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int depth, int sum) {
    if (depth == 4) {
        maxValue = max(maxValue, sum);
        return;
    }
    if (sum + (4 - depth) * maxCell <= maxValue) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int _x = x + direction[i].first;
        int _y = y + direction[i].second;
        if (isValid(_x, _y) && !visited[_x][_y]) {
            visited[_x][_y] = true;
            dfs(_x, _y, depth + 1, sum + board[_x][_y]);
            visited[_x][_y] = false;
        }
    }
}

void checkT(int x, int y) {
    // up: center + up + left + right
    if (isValid(x - 1, y) && isValid(x, y - 1) && isValid(x, y + 1))
        maxValue = max(maxValue, board[x][y] + board[x - 1][y] + board[x][y - 1] + board[x][y + 1]);
    // down
    if (isValid(x + 1, y) && isValid(x, y - 1) && isValid(x, y + 1))
        maxValue = max(maxValue, board[x][y] + board[x + 1][y] + board[x][y - 1] + board[x][y + 1]);
    // left
    if (isValid(x - 1, y) && isValid(x + 1, y) && isValid(x, y - 1))
        maxValue = max(maxValue, board[x][y] + board[x - 1][y] + board[x + 1][y] + board[x][y - 1]);
    // right
    if (isValid(x - 1, y) && isValid(x + 1, y) && isValid(x, y + 1))
        maxValue = max(maxValue, board[x][y] + board[x - 1][y] + board[x + 1][y] + board[x][y + 1]);
}

void find_max(int x, int y) {
    visited[x][y] = true;
    dfs(x, y, 1, board[x][y]);
    visited[x][y] = false;
    checkT(x, y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            maxCell = max(maxCell, board[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            find_max(i, j);
        }
    }

    cout << maxValue;
    return 0;
}