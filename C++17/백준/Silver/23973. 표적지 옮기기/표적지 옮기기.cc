#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

const int GRID_SIZE = 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int>>> grid; // 그리드 저장
    vector<pair<int, int>> dart;

    // 좌표 입력 및 그리드에 저장
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            if (input[j] == '1') {
                dart.push_back({i, j});
                int gridX = i / GRID_SIZE;
                int gridY = j / GRID_SIZE;
                grid[gridX * 1000 + gridY].push_back({i, j});
            }
        }
    }

    for (int i = 0; i < dart.size(); i++) {
        bool board[11] = {false};
        board[10] = true;
        int truthCount = 1;
        bool isEnd = true;

        // 현재 좌표가 속한 그리드 및 이웃 그리드 탐색
        int gridX = dart[i].first / GRID_SIZE;
        int gridY = dart[i].second / GRID_SIZE;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int neighborGrid = (gridX + dx) * 1000 + (gridY + dy);
                if (grid.find(neighborGrid) == grid.end()) continue;

                // 이웃 그리드 좌표 검사
                for (auto neighbor : grid[neighborGrid]) {
                    int nx = neighbor.first;
                    int ny = neighbor.second;

                    // 자기 자신 제외
                    if (nx == dart[i].first && ny == dart[i].second) continue;

                    // 거리 계산
                    int xDistance = abs(dart[i].first - nx);
                    int yDistance = abs(dart[i].second - ny);
                    if (xDistance > 9 || yDistance > 9) continue;

                    int score = 10 - max(xDistance, yDistance);

                    if (!board[score]) {
                        board[score] = true;
                        truthCount++;
                    } else {
                        isEnd = false;
                        break;
                    }
                }
                if (!isEnd) break;
            }
            if (!isEnd) break;
        }

        if (isEnd && truthCount == 10) {
            cout << dart[i].first << ' ' << dart[i].second;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
