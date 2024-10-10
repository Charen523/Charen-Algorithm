#include <iostream>
#include <vector>

using namespace std;

int main() {
	int targetNum;
	cin >> targetNum;

	vector<long long> numVector(targetNum + 1, 1);
	for (int i = 4; i < numVector.size(); i++) {
		numVector[i] = numVector[i - 1] + numVector[i - 3];
	}
	cout << numVector[targetNum];
}