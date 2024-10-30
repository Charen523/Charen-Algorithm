#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase;
	cin >> testCase;

	vector<int> input(testCase);
	vector<int> numSet;

	for (int i = 0; i < testCase; i++) {
		cin >> input[i];
	}

	numSet = input;
	sort(numSet.begin(), numSet.end());
	numSet.erase(unique(numSet.begin(), numSet.end()), numSet.end());

	unordered_map<int, int> orderedNum_index;
	int j = 0;
	for (const int& num : numSet) {
		orderedNum_index[num] = j;
		j++;
	}

	for (int i = 0; i < testCase; i++) {
		cout << orderedNum_index[input[i]] << ' ';
	}
}