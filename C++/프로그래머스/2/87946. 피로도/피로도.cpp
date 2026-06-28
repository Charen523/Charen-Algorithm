#include <string>
#include <vector>

using namespace std;

int tired;
int d_size;
vector<vector<int>> dv;
vector<bool> visited;
int answer = -1;

void back_tracking(int stack = 0, int counter = 0, int t = tired) {
    if (stack == d_size) {
        answer = max(answer, counter);
        return;
    }
    if (counter + (d_size - stack) < answer) return;
    
    for (int i = 0; i < d_size; i++) {
        if (visited[i]) continue;
        
        int least_t = dv[i][0];
        if (t >= least_t) {
            visited[i] = true;
            int use_t = dv[i][1];
            int new_t = t - use_t;
            back_tracking(stack + 1, counter + 1, new_t);    
        }
        
        visited[i] = false;
        back_tracking(stack + 1, counter, t);
    }
}

//k : 현재 피로도
int solution(int k, vector<vector<int>> dungeons) {
    tired = k;
    dv = dungeons;
    d_size = dv.size();
    visited.resize(d_size);
    
    back_tracking();
    
    return answer;
}