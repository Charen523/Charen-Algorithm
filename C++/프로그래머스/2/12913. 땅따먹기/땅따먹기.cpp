#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find_maxs(int& first, int& second, const vector<int>& v) {
    if (v[0] >= v[1]) {
        first = 0;
        second = 1;
    }
    else {
        first = 1;
        second = 0;
    }

    for (int i = 2; i < v.size(); i++) {
        if (v[i] > v[first]) {
            second = first;
            first = i;
        }
        else if (i != first && v[i] > v[second]) {
            second = i;
        }
    }
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int row = land.size();
    int col = land[0].size();
    
    vector<int> dp = land[0];
    for (int i = 1; i < row; i++) {
        int idx1, idx2;
        find_maxs(idx1, idx2, dp);
        int v1 = dp[idx1], v2 = dp[idx2];
        
        for (int j = 0; j < col; j++) {
            if (j != idx1) dp[j] = land[i][j] + v1;
            else dp[j] = land[i][j] + v2;
        }
    }

    answer = *max_element(dp.begin(), dp.end());
    return answer;
}