#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

vector<pair<int, int>> directions = {
    {-1, 0}, //위쪽
    {1, 0},  //아래쪽
    {0, 1},  //오른쪽
    {0, -1}  //왼쪽
};

int R, C, K;
vector<vector<int>> mapv;
int result = 0;

void dfs(int r, int c, int dist)
{
    if (dist > K) return;

    if (r == 0 && c == C - 1) {
        if (dist == K) result++;
        return;
    }

    for (auto d : directions) {
        int nr = r + d.first;
        int nc = c + d.second;

        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if (mapv[nr][nc] != 1) continue; // 1만 이동 가능 (0=방문, -1=벽)

        mapv[nr][nc] = 0;      // 방문 처리
        dfs(nr, nc, dist + 1);
        mapv[nr][nc] = 1;      // 되돌리기
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> K;

    mapv.assign(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++) {
        string input; cin >> input;
        for (int j = 0; j < C; j++) {
            mapv[i][j] = (input[j] == 'T') ? -1 : 1;
        }
    }

    // 시작점이 막혀있으면 0
    if (mapv[R - 1][0] != 1) {
        cout << 0;
        return 0;
    }

    // 시작점 방문 처리 후 dist=1로 시작
    mapv[R - 1][0] = 0;
    dfs(R - 1, 0, 1);

    cout << result;
    return 0;
}