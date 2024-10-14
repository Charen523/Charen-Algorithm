#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void sideMin(int dice[], int a, int b, int c, int d, int& min1, int& min2) {
	int diceIdxs[] = { a, b, c, d };
	
	min1 = diceIdxs[0]; 
	int minIdx = 0;
	for (int i = 1; i < 4; i++) {
		if (dice[diceIdxs[i]] < dice[min1]) {
			min1 = diceIdxs[i];
			minIdx = i;
		}
	}

	int leftIdx = (minIdx > 0) ? minIdx - 1 : 3;
	int rightIdx = (minIdx < 3) ? minIdx + 1 : 0;

	min2 = (dice[diceIdxs[leftIdx]] < dice[diceIdxs[rightIdx]]) ? diceIdxs[leftIdx] : diceIdxs[rightIdx];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	const int DICE_SIDES = 6;
	long long N;
	int minIndex = 0; 
	int dice[DICE_SIDES];
	
	cin >> N;

	if (N == 1) {
		int maxIdx = 0;
		int sum = 0;
		for (int i = 0; i < DICE_SIDES; i++) {
			cin >> dice[i];
			if (dice[i] > dice[maxIdx]) maxIdx = i;
			sum += dice[i];
		}
		sum -= dice[maxIdx];
		cout << sum;
		return 0;
	}

	for (int i = 0; i < DICE_SIDES; i++) {
		cin >> dice[i];
		if (dice[i] < dice[minIndex]) minIndex = i;
	}

	int minAngleSum = INT_MAX;
	int minSideSum = INT_MAX;
	for (int i = 0; i < DICE_SIDES; i++) {
		if (dice[minIndex] == dice[i]) {
			int sideSum, minSideIndex;
			if (i == 0 || i == 5) {
				sideMin(dice, 1, 3, 4, 2, minSideIndex, sideSum);
			}
			else if (i == 1 || i == 4) {
				sideMin(dice, 0, 3, 5, 2, minSideIndex, sideSum);
			}
			else {
				sideMin(dice, 4, 0, 1, 5, minSideIndex, sideSum);
			}
			sideSum = dice[minSideIndex] + dice[sideSum];

			if (minAngleSum > dice[minIndex] + sideSum) {
				minAngleSum = dice[minIndex] + sideSum;
			}
			if (minSideSum > dice[minIndex] + dice[minSideIndex]) {
				minSideSum = dice[minIndex] + dice[minSideIndex];
			}
		}
	}
	
	long long result = dice[minIndex] * ((N - 2) * (5 * N - 6))
		+ minSideSum * ( 4 * (2 * N - 3))
		+ minAngleSum * 4;

	cout << result;
}