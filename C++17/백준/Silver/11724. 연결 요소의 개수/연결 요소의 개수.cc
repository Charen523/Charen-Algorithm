#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int vertices, edges;
    cin >> vertices >> edges;

    UnionFind uf(vertices);
    for (int i = 0; i < edges; i++) {
        int dot1, dot2;
        cin >> dot1 >> dot2;
        uf.unite(dot1 - 1, dot2 - 1);  // 입력이 1부터 시작한다고 가정하여 0 기반으로 변환
    }

    int components = 0;
    for (int i = 0; i < vertices; i++) {
        if (uf.find(i) == i) {  // 루트 노드가 자기 자신인 경우 컴포넌트로 카운트
            components++;
        }
    }

    cout << components;
    return 0;
}
