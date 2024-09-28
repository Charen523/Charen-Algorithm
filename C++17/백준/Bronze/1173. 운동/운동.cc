#include <iostream>

using namespace std;

int main() {
	int targetT, minBeat, maxBeat, incBeat, restBeat;

	cin >> targetT >> minBeat >> maxBeat >> incBeat >> restBeat;

	if (minBeat + incBeat > maxBeat) {
		cout << -1 << '\n';
		return 0;
	}

	int curBeat = minBeat;
	int exT = 0;
	int totalT = 0;

	while (exT < targetT) {
		if (curBeat + incBeat <= maxBeat) {
			curBeat += incBeat;
			exT++;
		}
		else {
			curBeat = max(minBeat, curBeat - restBeat);
		}
		
		totalT++;
	}

	cout << totalT << '\n';
	return 0;
}