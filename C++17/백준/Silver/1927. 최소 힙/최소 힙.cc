#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
	vector<long long> heapSlot;

public:
	void Insert(long long value) {
		heapSlot.push_back(value);

		int curIdx = heapSlot.size() - 1;
		int parentIdx = (curIdx - 1) / 2;

		while (heapSlot[parentIdx] > heapSlot[curIdx]) {
			swap(heapSlot[parentIdx], heapSlot[curIdx]);
			curIdx = parentIdx;

			if (curIdx == 0) break;
			parentIdx = (curIdx - 1) / 2;
		}
	}

	long long Pop() {
		if (Size() == 0) return 0;

		long long popValue = heapSlot[0];
		
		//첫번째 원소 erase에 비해 효율적 연산.
		heapSlot[0] = heapSlot.back();
		heapSlot.pop_back(); 

		int curIdx = 0;
		int leftIdx = curIdx * 2 + 1;
		int rightIdx = curIdx * 2 + 2;

		while (leftIdx < Size()) {
			int smallerIdx = leftIdx;
			if (rightIdx < Size() && heapSlot[rightIdx] < heapSlot[leftIdx]) {
				smallerIdx = rightIdx;
			}
			if (heapSlot[curIdx] <= heapSlot[smallerIdx]) break;

			swap(heapSlot[curIdx], heapSlot[smallerIdx]);

			curIdx = smallerIdx;
			leftIdx = curIdx * 2 + 1;
			rightIdx = curIdx * 2 + 2;
		}

		return popValue;
	}

	int Size() {
		return heapSlot.size();
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testCount;
	cin >> testCount;

	MinHeap minHeap;
	for (int i = 0; i < testCount; i++) {
		long long value;
		cin >> value;
		if (value == 0) {
			cout << minHeap.Pop() << '\n';
		}
		else {
			minHeap.Insert(value);
		}
	}
}