#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//10:33:25 ~ 
int main() {
	int totalRice, radius;
	cin >> totalRice >> radius;

	int minX = 100, minY = 100;
	int maxX = -100, maxY = -100;
	vector<pair<int, int>> riceCoordinates(totalRice);
	for (int i = 0; i < totalRice; i++) {
		int x, y;
		cin >> x >> y;
		riceCoordinates[i] = { x, y };

		if (x < minX) minX = x;
		if (x > maxX) maxX = x;
		if (y < minY) minY = y;
		if (y > maxY) maxY = y;
	}

	/*idx : y값, value : x값*/
	vector<int> radiusRange;
	for (int i = 0; i <= radius; i++) {
		int j = (int)sqrt(radius * radius - i * i);
		radiusRange.push_back(j);
	}
	
	pair<int, int> maxRicePair;
	int maxRiceCount = 0;
	for (int x = minX; x <= maxX; x++) {
		for (int y = minY; y <= maxY; y++) { //radius = (x, y)
			int curRiceCount = 0; //rice in range
			
			for (pair<int, int> rice : riceCoordinates) {
				/*원점 기준 1사분면으로 이동*/
				int riceX = abs(rice.first - x);
				int riceY = abs(rice.second - y);

				if (riceY < radiusRange.size() && riceX <= radiusRange[riceY]) {
					curRiceCount++;
				}
			}

			if (curRiceCount > maxRiceCount) {
				maxRiceCount = curRiceCount;
				maxRicePair = { x, y };
			}
		}
	}

	cout << maxRicePair.first << ' ' << maxRicePair.second;
}