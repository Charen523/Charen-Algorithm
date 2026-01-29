#include <string>
#include <vector>

using namespace std;

pair<int, int> find_route(char op) {
    switch (op) {
        case 'N': return {-1, 0}; // di, dj
        case 'E': return {0, 1};
        case 'W': return {0, -1};
        case 'S': return {1, 0};
        default:  return {0, 0};
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    int rows = (int)park.size();
    int cols = (int)park[0].size();

    vector<vector<bool>> ok(rows, vector<bool>(cols, true));
    pair<int, int> cur = {0, 0}; // (row, col)

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char c = park[i][j];
            if (c == 'X') ok[i][j] = false;
            if (c == 'S') cur = {i, j};
        }
    }

    for (int i = 0; i < (int)routes.size(); ++i) {
        char op = routes[i][0];
        int len = routes[i][2] - '0'; // "E 2" 가정 (한 자리)

        auto [di, dj] = find_route(op);

        int nr = cur.first;
        int nc = cur.second;

        bool can = true;
        for (int step = 0; step < len; ++step) {
            nr += di;
            nc += dj;

            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) { can = false; break; }
            if (!ok[nr][nc]) { can = false; break; }
        }

        if (can) cur = {nr, nc};
    }

    return {cur.first, cur.second};
}