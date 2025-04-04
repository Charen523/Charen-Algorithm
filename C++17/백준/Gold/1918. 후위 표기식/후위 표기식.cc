#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node{
	string value;
	Node* left;
	Node* right;
	Node(string c, Node* l = 0, Node* r = 0) : value(c), left(l), right(r) {}
};

class Tree{
private:
	Node* root;
public:
	Tree(string c, string l, string r) {
		root = new Node(c, new Node(l), new Node(r));
	}

	Tree(string c, Node* l = nullptr, Node* r = nullptr) {
		root = new Node(c, l, r);
	}

	Node* get_root() {
		return root;
	}

	void add_left(Node* newTree) {
		newTree->left = root;
		root = newTree;
	}

	void add_right(Node* newTree) {
		Node* temp = root;
		while (temp->right != nullptr) {
			temp = temp->right;
		}
		temp->right = newTree;
	}

	void print(Node* n = nullptr) {
		if (n == nullptr) n = root;
		if (n->left) print(n->left);
		if (n->right) print(n->right);
		cout << n->value;
	}
};

int getPrecedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int main() {
	string infix;
	cin >> infix;

	stack<char> ops;
	stack<Node*> nodes;

	for (char token : infix) {
		if (isspace(token)) continue;

		if (isalpha(token)) {
			nodes.push(new Node(string(1, token)));
		}
		else if (token == '(') {
			ops.push(token);
		}
		else if (token == ')') {
			while (!ops.empty() && ops.top() != '(') {
				char op = ops.top(); ops.pop();
				Node* right = nodes.top(); nodes.pop();
				Node* left = nodes.top(); nodes.pop();
				nodes.push(new Node(string(1, op), left, right));
			}
			ops.pop();
		}
		else if (isOperator(token)) {
			while (!ops.empty() && getPrecedence(ops.top()) >= getPrecedence(token)) {
				char op = ops.top(); ops.pop();
				Node* right = nodes.top(); nodes.pop();
				Node* left = nodes.top(); nodes.pop();
				nodes.push(new Node(string(1, op), left, right));
			}
			ops.push(token);
		}
	}

	while (!ops.empty()) {
		char op = ops.top(); ops.pop();
		Node* right = nodes.top(); nodes.pop();
		Node* left = nodes.top(); nodes.pop();
		nodes.push(new Node(string(1, op), left, right));
	}

	Tree tree(nodes.top()->value, nodes.top()->left, nodes.top()->right);
	tree.print();
	cout << '\n';

	return 0;
}