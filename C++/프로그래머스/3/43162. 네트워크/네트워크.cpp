#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    int com_size = computers.size();
    vector<bool> visited(com_size, false);
    
    for (int i = 0; i < com_size; i++) {
        if (visited[i]) continue;
        
        stack<int> st; //dfs 
        st.push(i);
        
        while (!st.empty()) {
            int row = st.top();
            st.pop();
            for (int col = 0; col < com_size; col++) {
                if (visited[col]) continue;
                if (computers[row][col]) {
                    st.push(col);
                    visited[col] = true;
                }
            }
        }
        
        answer++;
    }
    
    return answer;
}