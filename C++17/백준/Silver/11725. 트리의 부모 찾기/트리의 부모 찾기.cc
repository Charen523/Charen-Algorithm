#include <iostream>
#include <vector>
#include <stack>  // 명시적 스택 사용

using namespace std;

void findParentsDFS(int root, vector<int>& answer, vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);  // 방문 배열
    stack<int> s;
    s.push(root);  // 루트 노드를 스택에 삽입

    while (!s.empty()) {
        int parValue = s.top();
        s.pop();
        visited[parValue] = true;

        for (int child : graph[parValue]) {
            if (!visited[child]) {
                answer[child] = parValue;  // 부모 저장
                s.push(child);  // 자식 노드 탐색
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);  // 인접 리스트
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> answer(n + 1);  // 부모 노드 배열
    findParentsDFS(1, answer, graph);  // DFS 탐색 시작 (루트: 1)

    for (int i = 2; i <= n; i++) {
        cout << answer[i] << '\n';  // 2번 노드부터 부모 출력
    }

    return 0;
}
