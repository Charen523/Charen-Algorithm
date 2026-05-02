#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    //arr1 * arr2. n * s s * m
    int n = arr1.size();
    int s = arr1[0].size();
    int m = arr2[0].size();
    vector<vector<int>> answer(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int result = 0;
            for (int k = 0; k < s; k++) {
                result += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = result;
        }
    }
    
    
    return answer;
}