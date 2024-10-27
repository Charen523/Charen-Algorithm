#include <iostream>
#include <vector>

using namespace std;

static void countColor(const vector<vector<bool>>& paper, int& whiteCount, int& blueCount, int size, int x, int y) {
	bool firstValue = paper[x][y];
	
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (firstValue != paper[i][j]) {
				int newSize = size / 2;
				countColor(paper, whiteCount, blueCount, newSize, x, y);
				countColor(paper, whiteCount, blueCount, newSize, x + newSize, y);
				countColor(paper, whiteCount, blueCount, newSize, x, y + newSize);
				countColor(paper, whiteCount, blueCount, newSize, x + newSize, y + newSize);
				return;
			}
		}
	}

	if (firstValue) blueCount++;
	else whiteCount++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<bool>> paper(N, vector<bool>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bool input;
			cin >> input;
			paper[i][j] = input;
		}
	}

	int whiteCount = 0, blueCount = 0;
	countColor(paper, whiteCount, blueCount, N,  0, 0);
	cout << whiteCount << '\n' << blueCount;
}