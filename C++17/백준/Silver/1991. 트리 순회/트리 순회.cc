#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
    char value;
    Node* left;
    Node* right;
    
    Node(char v) : value(v), left(nullptr), right(nullptr) {}
};

// 전위 순회
void preorder(Node* node) {
    if (node == nullptr) return;
    cout << node->value;
    preorder(node->left);
    preorder(node->right);
}

// 중위 순회
void inorder(Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->value;
    inorder(node->right);
}

// 후위 순회
void postorder(Node* node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;  // 트리의 노드 개수

    unordered_map<char, Node*> nodes;

    for (int i = 0; i < N; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;

        // 부모 노드를 찾거나 새로 생성
        if (nodes.find(parent) == nodes.end()) {
            nodes[parent] = new Node(parent);
        }
        Node* pNode = nodes[parent];

        // 왼쪽 자식 노드 처리
        if (left != '.') {
            if (nodes.find(left) == nodes.end()) {
                nodes[left] = new Node(left);
            }
            pNode->left = nodes[left];
        }

        // 오른쪽 자식 노드 처리
        if (right != '.') {
            if (nodes.find(right) == nodes.end()) {
                nodes[right] = new Node(right);
            }
            pNode->right = nodes[right];
        }
    }

    // 루트 노드는 항상 'A'라고 가정
    Node* root = nodes['A'];

    // 전위, 중위, 후위 순회 출력
    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';

    return 0;
}