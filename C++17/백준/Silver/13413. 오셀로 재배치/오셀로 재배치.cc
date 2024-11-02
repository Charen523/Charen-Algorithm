#include <iostream>
#include <string>
#include <algorithm> // max 사용을 위해 포함

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--) {
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

        cout << max(whiteCount, blackCount) << '\n';
    }

    return 0;
}
