#include <iostream>
#include <vector>
#include <string>
using namespace std;

int R, C;
vector<string> board;
bool alpha[26]; // 알파벳 사용 여부
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1, 1 };
int result = 0;

void dfs(int x, int y, int count) {
    result = max(result, count);

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
            int idx = board[nx][ny] - 'A';
            if (!alpha[idx]) {
                alpha[idx] = true;
                dfs(nx, ny, count + 1);
                alpha[idx] = false; // 백트래킹
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    board.resize(R);
    for (int i = 0; i < R; ++i) {
        cin >> board[i];
    }

    alpha[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << result << '\n';
    return 0;
}
