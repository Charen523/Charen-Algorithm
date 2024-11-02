#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase;
	cin >> testCase;

	string result = "";

	for (int i = 0; i < testCase; i++) {
		int pieceCount;
		cin >> pieceCount;

		string curPieceState, targetPieceState;
		cin >> curPieceState >> targetPieceState;

		int whiteCount = 0, blackCount = 0;
		
		for (int i = 0; i < pieceCount; i++) {
			if (curPieceState[i] != targetPieceState[i]) {
				if (curPieceState[i] == 'W') {
					whiteCount++;
				}
				else {
					blackCount++;
				}
			}
		}

		int testResult = (whiteCount > blackCount) ? whiteCount : blackCount;
		result += to_string(testResult) + '\n';
	}

	cout << result;
}