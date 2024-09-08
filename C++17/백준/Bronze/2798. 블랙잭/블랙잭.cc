#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int cardCount, targetNum;
	vector<int> cardVec;
	int result = 0;

	cin >> cardCount >> targetNum;
	for (int i = 0; i < cardCount; i++) {
		int input;
		cin >> input;
		cardVec.push_back(input);
	}

	sort(cardVec.begin(), cardVec.end());

	for (int i = cardCount - 1; i > 1; i--) {
		if (cardVec[i] >= targetNum) continue;
		for (int j = i - 1; j > 0; j--) {
			if (cardVec[i] + cardVec[j] >= targetNum) continue;
			for (int k = j - 1; k >= 0; k--) {
				int newResult = cardVec[i] + cardVec[j] + cardVec[k];
				if (newResult > targetNum) continue;
				else if (newResult > result) result = newResult;
			}
		}
	}

	cout << result;
}