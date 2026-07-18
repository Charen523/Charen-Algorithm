#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int b_size = order.size();
    
    stack<int> st;
    int ptr = 1;
    for (int i = 0; i < b_size; i++) {
        int value = order[i];
        if (!st.empty() && st.top() == value) {
            st.pop();
            answer++;
            continue;
        }
        
        while (ptr < value) {
            st.push(ptr);
            ptr++;
        }
        if (ptr == value) {
            answer++;
            ptr++;
        }
        else break;
    }
    
    return answer;
}