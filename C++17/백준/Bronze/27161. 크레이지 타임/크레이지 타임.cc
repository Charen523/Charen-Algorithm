#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

int TimeCounter(int prevTime, bool isClockwise);
string BoolToString(int isMid);

int main() {
	int cardCount;
	vector<tuple<bool, int>> cards;
	const string hourGlass = "HOURGLASS";
	
	cin >> cardCount;
	for (int i = 0; i < cardCount; i++) {
		string cardType;
		bool isReverse = false;
		int cardNum;
		cin >> cardType >> cardNum;
		if (cardType == hourGlass) isReverse = true;
		cards.push_back(make_tuple(isReverse, cardNum));
	}
	
	int curTime = 0;
	bool isClockwise = true;
	for (const auto& card : cards) {
		curTime = TimeCounter(curTime, isClockwise);
		if (get<0>(card)) {
			if (get<1>(card) != curTime) {//시간역행, 과부하x.
				isClockwise = !isClockwise;
			}
		}
		else if (get<1>(card) == curTime) {//동기화, 과부하x.
			cout << curTime << " " << BoolToString(true) << endl;
			continue;
		}
		cout << curTime << " " << BoolToString(false) << endl;
	}
}

int TimeCounter(int prevTime, bool isClockwise) {
	if (isClockwise) {
		prevTime++;
		if (prevTime > 12) prevTime -= 12;
	}
	else {
		prevTime--;
		if (prevTime < 1) prevTime += 12;
	}
	return prevTime;
}

string BoolToString(int isMid) {
	if (isMid) return "YES";
	else return "NO";
}