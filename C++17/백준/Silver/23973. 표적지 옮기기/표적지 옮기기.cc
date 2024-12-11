#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm> // count 함수 사용을 위해 추가

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
                int gridKey = (i / GRID_SIZE) * 1000 + (j / GRID_SIZE);
                grid[gridKey].push_back({i, j});
            }
        }
    }

    for (const auto& center : dart) {
        bool board[11] = {false};
        board[10] = true;

        int gridX = center.first / GRID_SIZE;
        int gridY = center.second / GRID_SIZE;

        // 주변 9개의 그리드 탐색
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int neighborGrid = (gridX + dx) * 1000 + (gridY + dy);
                if (grid.find(neighborGrid) == grid.end()) continue;

                // 이웃 그리드의 좌표 검사
                for (const auto& neighbor : grid[neighborGrid]) {
                    if (neighbor == center) continue;

                    int xDistance = abs(center.first - neighbor.first);
                    int yDistance = abs(center.second - neighbor.second);
                    if (xDistance > 9 || yDistance > 9) continue;

                    int score = 10 - max(xDistance, yDistance);
                    if (board[score]) {
                        goto next_center; // 중복 점수 발생 시 다음 중심으로 이동
                    }
                    board[score] = true;
                }
            }
        }

        // 모든 점수를 채웠는지 확인
        if (count(board, board + 11, true) == 10) { // count를 사용해 true의 개수 확인
            cout << center.first << ' ' << center.second;
            return 0;
        }

    next_center:;
    }

    cout << -1;
    return 0;
}
