#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int board_size = 0;
vector<pair<int, int>> directions = {
    {-2, -1},
    {-2, 1},
    {0, -2},
    {0, 2},
    {2, -1},
    {2, 1}
};

bool is_valid(pair<int, int> pos) {
    if (pos.first < 0 || pos.first >= board_size
    || pos.second < 0 || pos.second >= board_size) 
        return false;
    else return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_size;
    pair<int, int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    int result = 0; //나이트의 최소 이동 횟수
    vector<vector<bool>> is_visited(board_size, vector<bool>(board_size));
    queue<pair<int, int>> bfs;
    bfs.push(start);

    bool isEnd = false;
    while (!isEnd) {
        isEnd = true;
        queue<pair<int, int>> nextBfs;
        while (!bfs.empty()) {
            pair<int, int> cur = bfs.front();
            bfs.pop();
            if (is_visited[cur.first][cur.second]) continue;

            for (auto d : directions) {
                pair<int, int> next = cur;
                next.first += d.first;
                next.second += d.second;
                if (is_valid(next)) {
                    isEnd = false; //하나의 노드라도 유효할 때

                    if (next.first == end.first
                    && next.second == end.second) {
                        result++;
                        cout << result; 
                        return 0;
                    }
                    nextBfs.push(next);
                }
            }
            is_visited[cur.first][cur.second] = true;
        }
        bfs = nextBfs;
        result++;
    }

    
    
    cout << -1; //가능한 모든 영역을 방문한 경우.
	return 0;
}