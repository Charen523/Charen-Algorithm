#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int candidateCount;
	cin >> candidateCount;

	vector<int> votes(candidateCount);
	priority_queue<int> maxHeap;
	for (int i = 0; i < candidateCount; i++) {
		cin >> votes[i];
		if (i > 0) maxHeap.push(votes[i]);
	}
	
	int result = 0;
	while (!maxHeap.empty() && votes[0] <= maxHeap.top()) {
		int topVotes = maxHeap.top();
		maxHeap.pop();
		topVotes--;
		votes[0]++;
		result++;
		maxHeap.push(topVotes);
	}
	cout << result;
}