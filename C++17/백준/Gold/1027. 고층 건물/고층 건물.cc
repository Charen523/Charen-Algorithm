#include <iostream>
#include <vector>

using namespace std;

static int countVisibleBuildings(const vector<int>& buildings, int index) {
	int sights = 0;

	for (int i = 0; i < index; i++) {
		double a = (double)(buildings[index] - buildings[i]) / (index - i);
		double b = buildings[index] - a * index;

		bool isHidden = false;
		for (int j = i + 1; j < index; j++) {
			if (a * j + b <= buildings[j]) {
				isHidden = true; break;
			}
		}

		if (!isHidden) sights++;
	}

	for (int i = index + 1; i < buildings.size(); i++) {
		double a = (double)(buildings[index] - buildings[i]) / (index - i);
		double b = buildings[index] - a * index;

		bool isHidden = false;
		for (int j = index + 1; j < i; j++) {
			if (a * j + b <= buildings[j]) {
				isHidden = true; break;
			}
		}
		if (!isHidden) sights++;
	}

	return sights;
}


int main() {
	int buildingCount;
	cin >> buildingCount;

	vector<int> buildings(buildingCount);
	for (int i = 0; i < buildingCount; i++) {
		cin >> buildings[i];
	}

	if (buildingCount == 1) {
		cout << 0; return 0;
	}

	int max = 0;
	for (int i = 0; i < buildingCount; i++) {
		int curSight = countVisibleBuildings(buildings, i);
		if (max < curSight) {
			max = curSight;
		}
	}

	cout << max;
}