#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int arrLength;
	cin >> arrLength;

	vector<int> sortVec;
	sortVec.resize(arrLength);

	for (int i = 0; i < arrLength; i++) {
		cin >> sortVec[i];
	}

	sort(sortVec.begin(), sortVec.end());

	for (int v : sortVec)
		cout << v << " ";
	cout << '\n';
}