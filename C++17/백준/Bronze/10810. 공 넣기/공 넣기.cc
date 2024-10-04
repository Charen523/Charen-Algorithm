#include <iostream>
#include <vector>

using namespace std;

int main() {
	int basketCount, testCase;
	cin >> basketCount >> testCase;

	vector<int> baskets(basketCount);

	for (int i = 0; i < testCase; i++) {
		int start, end, num;
		cin >> start >> end >> num;
		for (int i = start - 1; i < end; i++) {
			baskets[i] = num;
		}
	}

	for (int i = 0; i < basketCount; i++) {
		cout << baskets[i] << ' ';
	}
}