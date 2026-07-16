#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int row = triangle.size();
    vector<int> dp;
    dp.push_back(triangle[0][0]);
    for (int i = 1; i < row; i++) {
        vector<int> next(i + 1, 0);
        for (int j = 0; j < i; j++) {
            next[j] = max(next[j], dp[j] + triangle[i][j]);
            next[j + 1] = max(next[j + 1], dp[j] + triangle[i][j + 1]);
        }
        dp = next;
    }
    
    answer = *max_element(dp.begin(), dp.end());
    return answer;
}