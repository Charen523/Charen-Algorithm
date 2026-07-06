#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> tuples;
    
    int row_ptr = 0;
    string temp_int = "";
    
    s = s.substr(1, s.size() - 2);
    int s_size = s.size();
    for (int i = 0; i < s_size; i++) {
        char c = s[i];
        switch (c) {
            case '\{':
                tuples.push_back({});
                break;
            case ',':
                tuples[row_ptr].push_back(stoi(temp_int));
                temp_int = "";
                break;
            case '\}':
                tuples[row_ptr].push_back(stoi(temp_int));
                temp_int = "";
                row_ptr++;
                i++; //vector간 간격 무시
                break;
            default:
                temp_int += c;
                break;
        }
    }
    
    sort (tuples.begin(), tuples.end(), [](const vector<int> a, const vector<int> b){
         return a.size() < b.size();
    });
    
    unordered_set<int> result_hash;
    int t_size = tuples.size();
    for (int i = 0; i < t_size; i++){
        for (int j = 0; j < i + 1; j++) {
            int k = tuples[i][j];
            if (result_hash.find(k) != result_hash.end()) continue;
            answer.push_back(k);
            result_hash.insert(k);
        }
    }
    
    return answer;
}