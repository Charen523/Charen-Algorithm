#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int p_size = progresses.size();
    int release_day = 0;
    for (int i = 0; i < p_size; i++) {
        int left = 100 - progresses[i];
        int d_day = left / speeds[i];
        if (left % speeds[i] != 0) {
            d_day++;
        }
        
        if (release_day < d_day) { //배포 기준일
            release_day = d_day;
            answer.push_back(1);
        }
        else {
            answer.back()++;
        }
    }
    
    return answer;
}