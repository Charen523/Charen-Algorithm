#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase;
	cin >> testCase;
	
	vector<int> points;

	int prevPeak, curPeak;
	
	cin >> prevPeak >> curPeak;
	points.push_back(prevPeak);

	bool isUphill = curPeak > prevPeak;
	prevPeak = curPeak;

	for (int i = 2; i < testCase; i++) {
		cin >> curPeak;

		if (curPeak == prevPeak) {
			points.push_back(prevPeak);
			points.push_back(curPeak);

			i++;
			prevPeak = curPeak;
			cin >> curPeak;
			isUphill = curPeak > prevPeak;
		}
		else if (isUphill) {
			if (curPeak < prevPeak) {
				points.push_back(prevPeak);
				isUphill = false;
			}
		}
		else {
			if (curPeak > prevPeak) {
				points.push_back(prevPeak);
				isUphill = true;
			}
		}

		prevPeak = curPeak;
	}
	points.push_back(prevPeak);

	int maxUphill = 0;
	for (int i = 0; i < points.size() - 1; i++) {
		int curHill = points[i + 1] - points[i];
		if (curHill > maxUphill) maxUphill = curHill;
	}
	cout << maxUphill;
}