#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool visited[200000];
vector<int> graph[200000];
int index[200000];
void dfs(int start, int depth) {
    if (visited[start] == true) {
        return;
    }
    visited[start] = true;
    index[start] = depth;
    sort(graph[start].begin(), graph[start].end(), greater<int>());
    for (int i = 0; i < graph[start].size(); i++) {
        int y = graph[start][i];
        dfs(y, depth + 1);
    }
}


int main(void) {
    int n, m, start;
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(start, 0);
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            index[i] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << index[i] << '\n';
    }


}

