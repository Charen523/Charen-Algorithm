#include <iostream>
#include <map>
#include <climits>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int weeks;
	cin >> weeks;

	map<string, int> workTimes;
	for (int i = 0; i < weeks; i++) {
		for (int timeline = 0; timeline < 4; timeline++) {
			int curTime = 0;

			switch (timeline) {
			case 0:
			case 2:
				curTime = 4;
				break;
			case 1:
				curTime = 6;
				break;
			case 3:
				curTime = 10;
				break;
			}
			
			for (int day = 0; day < 7; day++) {
				string name;
				cin >> name;

				if (name == "-") continue;
				else if (workTimes.count(name) == 0) {
					workTimes.emplace(name, curTime);
				}
				else {
					workTimes[name] += curTime;
				}
			}
		}
	}

	if (workTimes.empty()) {
		cout << "Yes";
		return 0;
	}

	int max = INT_MIN, min = INT_MAX;
	for (const auto& time : workTimes) {
		if (max < time.second) max = time.second;
		if (min > time.second) min = time.second;
	}

	if (max - min > 12) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
}