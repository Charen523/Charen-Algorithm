#include <iostream>
#include <vector>

using namespace std;

int giveBribe(vector<int>& votes) {
	int maxIndex = 0;
	for (int i = 0; i < votes.size(); i++) {
		if (votes[maxIndex] <= votes[i])
			maxIndex = i;
	}
	if (maxIndex != 0) {
		votes[maxIndex]--;
		votes[0]++;
	}

	return maxIndex;
}

int main() {
	int candidateCount;
	cin >> candidateCount;

	vector<int> votes(candidateCount);
	for (int i = 0; i < candidateCount; i++) {
		cin >> votes[i];
	}
	
	int result = 0;
	while (giveBribe(votes) != 0) { result++; }
	cout << result;
}