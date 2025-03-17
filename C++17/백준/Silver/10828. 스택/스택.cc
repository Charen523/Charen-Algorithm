#include <iostream>
#include <string>

using namespace std;

struct Node {
	int value;
	Node* bottom;

	Node(const int v) : value(v), bottom(nullptr) {}
};

class Stack {
private:
	Node* head;
	int count;

public:
	Stack() : head(nullptr), count(0) {}

	~Stack() {
		while (head != nullptr) {
			Node* temp = head;
			head = head->bottom;
			delete temp;
		}
	}

	void push(int v) {
		Node* newNode = new Node(v);
		newNode->bottom = head;
		head = newNode;

		count++;
	}

	void pop() {
		if (count == 0) cout << -1 << '\n';
		else {
			cout << head->value << '\n';

			Node* temp = head;
			head = head->bottom;
			delete temp;

			count--;
		}
	}

	void size() const {
		cout << count << '\n';
	}

	void empty() const {
		cout << (count == 0) << '\n';
	}

	void top() const {
		if (count == 0) cout << -1 << '\n';
		else cout << head->value << '\n';
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int commandCount;
	cin >> commandCount;

	Stack* s = new Stack();
	for (int i = 0; i < commandCount; i++) {
		string command;
		cin >> command;

		if (command == "push") {
			int value;
			cin >> value;
			s->push(value);
		}
		else if (command == "pop") {
			s->pop();
		}
		else if (command == "size") {
			s->size();
		}
		else if (command == "empty") {
			s->empty();
		}
		else if (command == "top") {
			s->top();
		}
	}
}