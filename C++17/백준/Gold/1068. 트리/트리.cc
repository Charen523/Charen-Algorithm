#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
int root = -1;
vector<bool> removed;
vector<int> parent_info;

void insert_tree(int N, const vector<int>& parents) {
    tree.resize(N);
    removed.resize(N, false);
    parent_info = parents;

    for (int i = 0; i < N; ++i) {
        if (parents[i] == -1) {
            root = i;
        }
        else {
            tree[parents[i]].push_back(i);
        }
    }
}

void remove_node(int node) {
    removed[node] = true;

    if (parent_info[node] != -1) {
        vector<int>& siblings = tree[parent_info[node]];
        siblings.erase(std::remove(siblings.begin(), siblings.end(), node), siblings.end());
    }

    for (int child : tree[node]) {
        remove_node(child);
    }
}


void count_leaf() {
    int leaves = 0;
    for (int i = 0; i < tree.size(); i++) {
        if (removed[i]) continue;
        if (tree[i].size() == 0)
            leaves++;
    }
    cout << leaves << '\n';
}

int main() {
    int N;
    cin >> N;

    vector<int> parents(N);
    for (int i = 0; i < N; ++i) {
        cin >> parents[i];
    }

    insert_tree(N, parents);
    
    int node_deleted;
    cin >> node_deleted;
    remove_node(node_deleted);

    count_leaf();

    return 0;
}