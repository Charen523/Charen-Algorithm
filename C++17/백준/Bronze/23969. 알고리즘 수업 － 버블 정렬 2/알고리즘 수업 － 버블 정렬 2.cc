#include <iostream>
#include <vector>

using namespace std;

bool bubbleSort(vector<int>& arr, int swapCount) {
	for (int i = arr.size(); i > 1; i--) {
		for (int j = 0; j < i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapCount--;

				if (swapCount == 0) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	int arrSize, swapCount;
	cin >> arrSize >> swapCount;

	vector<int> bubbleArr(arrSize);
	for (int i = 0; i < arrSize; i++) {
		cin >> bubbleArr[i];
	}

	bool isOver = bubbleSort(bubbleArr, swapCount);

	if (isOver) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < arrSize; i++) {
		cout << bubbleArr[i] << ' ';
	}
	return 0;
}