#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
	vector<int> queue;

public:
	Queue(int size){
		for (int i = 0; i < size; i++) {
			queue.push_back(i + 1);
		}
	}

	void Enqueue(int value) {
		queue.push_back(value);
	}

	int Dequeue() {
		if (isEmpty()) return NULL;
		int temp = queue[0];
		queue.erase(queue.begin());
		return temp;
	}

	bool isEmpty() const {
		return queue.size() == 0;
	}

	int top() const {
		if (isEmpty()) return NULL;
		return queue[0];
	}

	int size() const {
		return queue.size();
	}
};

int main() {
	int count, index;
	cin >> count >> index;

	Queue table(count);

	cout << '<';
	while (table.size() > 1) {
		for (int i = 0; i < index - 1; i++) {
			int temp = table.Dequeue();
			table.Enqueue(temp);
		}
		cout << table.Dequeue() << ", ";
	}
	cout << table.Dequeue() << ">\n";
}