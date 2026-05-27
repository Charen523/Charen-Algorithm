#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int findSize(vector<vector<int>>& picture, int startX, int startY) {
    int result = 0;
    
    int row = picture.size();
    int col = picture.size();
    
    int color = picture[startX][startY];
    queue<pair<int, int>> q;
    q.push({startX, startY});
    while (!q.empty()) {
        pair<int, int> curPos = q.front();
        q.pop();
        
        for (auto [x, y] : direction) {
            x += curPos.first;
            y += curPos.second;
            if (x >= 0 && x < row && y >= 0 && y < col) {
                if (picture[x][y] == color) {
                    q.push({x, y});
                    picture[x][y] = 0;
                    result++;
                }
            }
        }
    }
    return result;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] == 0) continue;
            int curSize = findSize(picture, i, j);
            number_of_area++;
            max_size_of_one_area = max(curSize, max_size_of_one_area);
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}