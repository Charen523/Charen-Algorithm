#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int startPos, endPos;
	cin >> startPos >> endPos;

	if (startPos == endPos) {
		cout << 0;
		return 0;
	}
	else if (startPos > endPos) {
		cout << startPos - endPos;
		return 0;
	}

	int maxSize = (endPos * 2 < 100000) ? endPos * 2 : 100000;
	vector<bool> reachTime(maxSize + 1);

	queue<int> curStepPos;
	curStepPos.push(startPos);
	reachTime[startPos] = true;

	int step = 0;
	while (!reachTime[endPos]) {
		int qSize = curStepPos.size();
		for (int i = 0; i < qSize; i++) {
			int curPos = curStepPos.front();
			curStepPos.pop();

			int newPos = curPos - 1;
			if (newPos > 0 && reachTime[newPos] == false) {
				curStepPos.push(newPos);
				reachTime[newPos] = true;
			}

			newPos = curPos + 1;
			if (newPos < reachTime.size() && reachTime[newPos] == false) {
				curStepPos.push(newPos);
				reachTime[newPos] = true;
			}

			newPos = curPos * 2;
			if (newPos > 0 && newPos < reachTime.size() && reachTime[newPos] == false) {
				curStepPos.push(newPos);
				reachTime[newPos] = true;
			}
		}
		step++;
	}
	cout << step;
}