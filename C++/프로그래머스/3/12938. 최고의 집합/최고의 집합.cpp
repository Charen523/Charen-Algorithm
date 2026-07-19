#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if (n > s) return {-1};
    
    int min_num = s / n;
    int left = s % n;
    vector<int> answer(n, min_num);
    for (int i = 1; i <= left; i++) {
        answer[n - i]++;
    }
    
    return answer;
}