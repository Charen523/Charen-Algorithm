#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* next;

	Node(int v) : value(v), next(nullptr) {}
};

class Queue {
private:
	Node* head;
	Node* tail;
	int length;

public:
	Queue() : head(nullptr), tail(nullptr), length(0) {}

	~Queue() {
		while (head != nullptr) {
			Node* temp = head->next;
			delete head;
			head = temp;
		}
	}

	void push(int value) {
		Node* newNode = new Node(value);

		Node* temp = tail;
		tail = newNode;

		if (length == 0) head = newNode;
		else temp->next = newNode;

		length++;
	}

	void pop() {
		if (length != 0) {
			cout << head->value << '\n';

			Node* temp = head;
			head = temp->next;
			delete temp;

			length--;

			if (length == 0) tail = nullptr;
		}
		else {
			cout << -1 << '\n';
		}
	}

	void size() const {
		cout << length << '\n';
	}

	void empty() const {
		cout << (length == 0) << '\n';
	}

	void front() const {
		if (length == 0) {
			cout << -1 << '\n';
		}
		else {
			cout << head->value << '\n';
		}
	}

	void back() const {
		if (length == 0) {
			cout << -1 << '\n';
		}
		else {
			cout << tail->value << '\n';
		}
	}
};

int main() {
	int count;
	cin >> count;

	Queue q;
	for (int i = 0; i < count; i++) {
		string command;
		cin >> command;

		if (command == "push") {
			int value; 
			cin >> value;
			q.push(value);
		}
		else if (command == "pop") {
			q.pop();
		}
		else if (command == "size") {
			q.size();
		}
		else if (command == "empty") {
			q.empty();
		}
		else if (command == "front") {
			q.front();
		}
		else if (command == "back") {
			q.back();
		}
	}
}