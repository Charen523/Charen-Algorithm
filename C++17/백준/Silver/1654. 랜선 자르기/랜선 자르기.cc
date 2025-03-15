#include <iostream>
#include <vector>

using namespace std;

int main() {
	int ownedLines, neededLines;
	cin >> ownedLines >> neededLines;

	vector<int> lineLengths;
	lineLengths.reserve(ownedLines);
	
	unsigned int max = 0;
	for (int i = 0; i < ownedLines; i++) {
		int value;
		cin >> value;
		lineLengths.push_back(value);
		if (value > max) max = value;
	}

	unsigned int min = 1;
	unsigned int mid;
	unsigned int result = 0;
	
	while (min <= max) {
		mid = (min + max) / 2;

		int curLines = 0;
		for (int line : lineLengths) {
			curLines += line / mid;
		}

		if (curLines >= neededLines) {
			min = mid + 1;
			result = (result < mid) ? mid : result;
		}
		else max = mid - 1;
	}

	cout << result << endl;
}