#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
	vector<int> queue;

public:
	Queue(int size){
		queue.reserve(size);
		for (int i = 0; i < size; i++) {
			queue.push_back(i + 1);
		}
	}

	void Enqueue(int value) {
		queue.push_back(value);
	}

	int Dequeue() {
		int frontValue = queue.front();
		queue.erase(queue.begin());
		return frontValue;
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