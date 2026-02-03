#include <string>
#include <vector>
#include <stack>

using namespace std;

int check_square(const vector<vector<string>>& park, pair<int, int> pos) {
    int row_size = (int)park.size();
    int col_size = (int)park[0].size();

    int size = min(row_size - pos.first, col_size - pos.second);

    int down = 1;
    while (pos.first + down < row_size && park[pos.first + down][pos.second] == "-1") down++;
    size = min(size, down);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (park[pos.first + i][pos.second + j] != "-1") {
                size = max(i, j);
            }
        }
    }

    return size;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    
    int row_size = park.size();
    int col_size = park[0].size();
    
    int max_square = 0;
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (park[i][j] != "-1") continue;
            int new_size = check_square(park, {i, j}); 
            max_square =  max_square < new_size ? new_size : max_square;
        }
    }
    
    for (int i = 0; i < mats.size(); i++) {
        if (mats[i] > max_square) continue;
        if (answer < mats[i]) answer = mats[i];
    }
    
    return answer;
}