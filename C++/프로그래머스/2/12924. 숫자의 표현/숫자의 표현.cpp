#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int max_count = 0;
    for (int sum = 0; sum + (max_count + 1) <= n; ) {
        max_count++;
        sum += max_count;
    }
    
    for (int i = 1; i <= max_count; i++) {
        float k = (float)n / i;
        
        if (i % 2 == 0) {
            k += 0.5;
        }
        
        if (k == (int)k && k - (i / 2) > 0) 
            answer++;
    }
    
    return answer;
}