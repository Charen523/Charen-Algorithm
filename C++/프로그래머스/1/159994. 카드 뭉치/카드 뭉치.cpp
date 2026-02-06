#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    int size1 = cards1.size(), size2 = cards2.size();
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < goal.size(); i++) {
        if (idx1 < size1 && goal[i] == cards1[idx1]) idx1++;
        else if (idx2 < size2 && goal[i] == cards2[idx2]) idx2++;
        else {
            answer = "No"; break;
        }
    }
    
    return answer;
}