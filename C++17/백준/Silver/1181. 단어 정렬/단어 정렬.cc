#include <iostream>

using namespace std;

struct Node {
public:
	string word;
	Node* left;
	Node* right;
	Node(const string& w) : word(w), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
	Node* root;

	Node* insert(Node* node, const string& word) {
		if (node == nullptr) {
			return new Node(word);
		}

		if (word.size() < node->word.size()) {
			node->left = insert(node->left, word);
		}
		else if (word.size() > node->word.size()) {
			node->right = insert(node->right, word);
		}
		else {
			if (word < node->word) {
				node->left = insert(node->left, word);
			}
			else if (word > node->word) {
				node->right = insert(node->right, word);
			}
		}

		return node;
	}

	void inorder(Node* node) const {
		if (node == nullptr) return;
		inorder(node->left);
		cout << node->word << endl;
		inorder(node->right);
	}

	void destroyTree(Node* node) {
		if (node != nullptr) {
			destroyTree(node->left);
			destroyTree(node->right);
			delete node;
		}
	}
public:
	BinarySearchTree() : root(nullptr) {}

	void insert(const string& word) {
		root = insert(root, word);
	}

	void display() const {
		inorder(root);
	}

	~BinarySearchTree() {
		destroyTree(root);
	}
};

int main() {
	int wordCount;
	cin >> wordCount;


	BinarySearchTree bst;
	for (int i = 0; i < wordCount; i++) {
		string curWord;
		cin >> curWord;
		bst.insert(curWord);
	}

	bst.display();
}