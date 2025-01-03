#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

unordered_map<char, vector<pair<int, int>>> mapInfo;
pair<int, int> startPoint;
pair<int, int> lastPoint;

int getDistance(pair<int, int> a, pair<int, int> b) {
	int result = 0;
	result += abs(a.first - b.first);
	result += abs(a.second - b.second);
	return result;
}

int getTotalDistances(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	int result = 0;

	result += getDistance(startPoint, a);
	result += getDistance(a, b);
	result += getDistance(b, c);
	result += getDistance(c, lastPoint);

	return result;
}

void checkMinDistances(int& minDistance, char& result, char target) {
	vector<pair<int, int>> curPoints = mapInfo[target];
	vector<int> distances(6);

	distances[0] = getTotalDistances(curPoints[0], curPoints[1], curPoints[2]);
	distances[1] = getTotalDistances(curPoints[0], curPoints[2], curPoints[1]);
	distances[2] = getTotalDistances(curPoints[1], curPoints[0], curPoints[2]);
	distances[3] = getTotalDistances(curPoints[1], curPoints[2], curPoints[0]);
	distances[4] = getTotalDistances(curPoints[2], curPoints[0], curPoints[1]);
	distances[5] = getTotalDistances(curPoints[2], curPoints[1], curPoints[0]);
	sort(distances.begin(), distances.end());

	if (distances[0] < minDistance) {
		minDistance = distances[0];
		result = target;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n; //토핑토핑지도의 크기.

	/*
	* X : 빈 땅
	* H : 집
	* # : 쿠키크루삥뽕
	* W, C, B, J : 호두, 초콜릿, 베리, 젤리 토핑.
	*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char input;
			cin >> input;
			mapInfo[input].push_back({ i, j });
		}
	}

	char result = ' ';
	int minDistance = INT_MAX;
	startPoint = mapInfo['H'][0];
	lastPoint = mapInfo['#'][0];

	checkMinDistances(minDistance, result, 'J');
	checkMinDistances(minDistance, result, 'C');
	checkMinDistances(minDistance, result, 'B');
	checkMinDistances(minDistance, result, 'W');

	switch (result) {
	case 'W':
		cout << "Tanker";
		break;
	case 'C':
		cout << "Healer";
		break;
	case 'B':
		cout << "Mage";
		break;
	case 'J':
		cout << "Assassin";
		break;
	}
	return 0;
}