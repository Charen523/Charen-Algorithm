#include <iostream>
#include <vector>

using namespace std;

int main() {
	int subjectCount;
	cin >> subjectCount;

	vector<int> scores;
	scores.reserve(subjectCount);

	float max = 0;
	for (int i = 0; i < subjectCount; i++) {
		int value;
		cin >> value;
		scores.push_back(value);
		if (value > max) max = value;
	}

	float newScoreSum = 0;
	for (int i = 0; i < subjectCount; i++) {
		newScoreSum += scores[i] / max * 100;
	}

	cout << newScoreSum / subjectCount << endl;
}