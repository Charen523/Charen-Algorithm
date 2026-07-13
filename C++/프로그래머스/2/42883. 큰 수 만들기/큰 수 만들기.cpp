#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int ptr = 0;
    int result_size = number.size() - k;
    while (answer.size() < result_size) {
        char target = 0;
        int max_idx = 0;
        for (int i = ptr; i <= ptr + k; i++) {
            if (target < number[i]) {
                target = number[i];
                max_idx = i;
            }
        }
        
        answer += target;
        k -= max_idx - ptr;
        ptr = max_idx + 1;
    }
    
    return answer;
}