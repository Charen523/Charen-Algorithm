#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<char, int>> cards(5);//5: 카드개수
	for (int i = 0; i < cards.size(); i++) { 
		cin >> cards[i].first >> cards[i].second;
	}

	// 정렬 : 숫자 작은순 -> 큰순
	sort(cards.begin(), cards.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
		return a.second < b.second;
		});

	bool isFlush = true, isStraight = true;
	unordered_map<int, int> cardNumMap;
	cardNumMap[cards[0].second] = 1;
	for (int i = 1; i < cards.size(); i++) {
		if (isFlush && cards[i].first != cards[0].first)
			isFlush = false;

		if (isStraight && cards[i].second != cards[i - 1].second + 1) {
			isStraight = false;
		}

		if (cardNumMap.end() == cardNumMap.find(cards[i].second)) {
			cardNumMap.emplace(cards[i].second, 1);
		}
		else {
			cardNumMap[cards[i].second]++;
		}
	}

	if (isFlush && isStraight) { //1 : 최고숫자 + 900
		cout << 900 + cards[4].second;
		return 0;
	}
	
	int two1 = 0, two2 = 0, three = 0, four = 0;
	for (const auto& m : cardNumMap) {
		switch (m.second) {
		case 2:
			if (two1 == 0)
				two1 = m.first;
			else
				two2 = m.first;
			break;
		case 3:
			three = m.first;
			break;
		case 4:
			four = m.first;
			break;
		default:
			break;
		}
	}
	
	if (four != 0) { //2 : 같은 숫자 + 800
		cout << 800 + four;
		return 0;
	}
	else if (three != 0 && two1 != 0) { //3 : x * 10 + y + 700
		cout << 700 + three * 10 + two1;
		return 0;
	}
	else if (isFlush) { //가장 큰 숫자 + 600
		cout << 600 + cards[4].second;
		return 0;
	}
	else if (isStraight) { //가장 큰 숫자 + 500
		cout << 500 + cards[4].second;
		return 0;
	}
	else if (three != 0) { //같은 숫자 + 400
		cout << 400 + three;
		return 0;
	}
	else if (two1 != 0 && two2 != 0) { //큰 숫자 * 10 + 작은 숫자 + 300
		if (two1 < two2) swap(two1, two2);
		cout << 300 + two1 * 10 + two2;
		return 0;
	}
	else if (two1 != 0) {//같은 숫자 + 200
		cout << 200 + two1;
		return 0;
	}
	else { //가장 큰 숫자 + 100
		cout << 100 + cards[4].second;
		return 0;
	}
}