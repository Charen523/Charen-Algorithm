#include <string>
#include <vector>

using namespace std;

//공원, 시작 좌표, row 길이, col 길이
int check_square(const vector<vector<string>>& park, int x, int y, int r, int c) {
    int max_size = min(r - x, c - y);
    for (int i = 0; i < max_size; i++) {
        for (int j = 0; j < max_size; j++) {
            if (park[x + i][y + j] != "-1") max_size = max(i, j);
        }
    }
    
    return max_size;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    
    int row_size = park.size();
    int col_size = park[0].size();
    
    int max_size = 0;
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (park[i][j] != "-1") continue;
            max_size = max(max_size, check_square(park, i, j, row_size, col_size));
        }
    }
    
    for (int i = 0; i < mats.size(); i++) {
        if (max_size < mats[i]) continue;
        answer = max(answer, mats[i]);
    }
    return answer;
}