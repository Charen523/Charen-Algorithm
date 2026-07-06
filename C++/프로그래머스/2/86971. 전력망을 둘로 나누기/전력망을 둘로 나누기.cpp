#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> graph;
int N;

int abs(int i) {
    return i >= 0 ? i : -i;
}

int dfs(int v, int w) {
    int g_size = 0;
    vector<bool> visited(N, false);
    
    stack<int> st;
    st.push(0);
    visited[0] = true;
    while (!st.empty()) {
        int temp = st.top();
        g_size++;
        st.pop();
        
        for (int i = 0; i < graph[temp].size(); i++) {
            int next = graph[temp][i];
            if ((temp == v && next == w) || (temp == w && next == v)) continue;
            if (visited[next]) continue;
            st.push(next);
            visited[next] = true;
        }
    }
    
    return g_size;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    N = n;
    
    graph.resize(n);
    for (int i = 0; i < wires.size(); i++) {
        int v = wires[i][0] - 1;
        int w = wires[i][1] - 1;
        graph[v].push_back(w);
        graph[w].push_back(v);
    }
    
    for (int i = 0; i < wires.size(); i++) {
        int v = wires[i][0] - 1;
        int w = wires[i][1] - 1;
        
        int sizeA = dfs(v, w);
        int sizeB = n - sizeA;
        int delta = abs(sizeA - sizeB);
        
        answer = min(answer, delta);
    }
    
    return answer;
}