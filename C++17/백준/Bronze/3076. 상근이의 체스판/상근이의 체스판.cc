#include <iostream>

using namespace std;

int main() {
	int R, C, A, B;
	cin >> R >> C >> A >> B;

	bool isBlackRow = false, isBlackColumn = false;
	for (int i = 0; i < R; i++) {
		isBlackRow = !isBlackRow;
		for (int x = 0; x < A; x++) {
			isBlackColumn = !isBlackRow;
			for (int j = 0; j < C; j++) {
				isBlackColumn = !isBlackColumn;
				for (int y = 0; y < B; y++) {
					if (isBlackColumn)
						cout << "X";
					else {
						cout << ".";
					}
				}
			}
			cout << '\n';
		}
	}
}