#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> board(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> board[i];
	}

	vector<int> dice(N);
	for (int i = 0; i < M; i++) {
		cin >> dice[i];
	}

	int diceThrown;
	int curStand = 1;
	for (diceThrown = 0; diceThrown < M; diceThrown++) {
		curStand += dice[diceThrown];
		if (curStand >= N) break;
		curStand += board[curStand];
		if (curStand >= N) break;
	}
	cout << ++diceThrown;
}