#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	vector<int> aVector(count); 
	int sum = 0;

	for (int i = 1; i < count; i++) {
		int value;
		cin >> value;
		sum += value;
		aVector[i] = sum;
	}

	int min = *min_element(aVector.begin(), aVector.end());
	int max = *max_element(aVector.begin(), aVector.end());

	if ((max - min) == count - 1) {
		int offset = 1 - min;

		for (int num : aVector)
			cout << num + offset << ' ';

		cout << '\n';
	}
	else {
		cout << -1 << '\n';
	}
}