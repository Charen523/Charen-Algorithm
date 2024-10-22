#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int testCount;
	cin >> testCount;

	vector<pair<int, int>> meetings(testCount);

	for (int i = 0; i < testCount; i++) {
		cin >> meetings[i].second >> meetings[i].first;
	}

	sort(meetings.begin(), meetings.end());

	int reserveCount = 0;
	int curLastTime = 0;

	for (const auto& [end, start] : meetings) {
		if (start >= curLastTime) {
			curLastTime = end;
			reserveCount++;
		}
	}

	cout << reserveCount;
}