#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer, board_size;
vector<int> queen_stack; //index = 행, value = 열

void back_tracking(int row) {
    if (row == board_size) {
        answer++;
        return;
    }
    
    vector<bool> row_flag(board_size, false);
    for (int i = 0; i < row; i++) {
        int curQ = queen_stack[i];
        row_flag[curQ] = true;
        
        int delta = row - i;
        int low_bound = curQ - delta;
        int high_bound = curQ + delta;
        
        if (low_bound >= 0) {
            row_flag[low_bound] = true;
        }
        if (high_bound < board_size) {
            row_flag[high_bound] = true;
        }
    }
    
    for (int i = 0; i < board_size; i++) {
        if (row_flag[i]) continue;
        
        queen_stack.push_back(i);
        back_tracking(row + 1);
        queen_stack.pop_back();
    }
}

int solution(int n) {
    answer = 0;
    board_size = n;
    
    back_tracking(0);
    
    return answer;
}