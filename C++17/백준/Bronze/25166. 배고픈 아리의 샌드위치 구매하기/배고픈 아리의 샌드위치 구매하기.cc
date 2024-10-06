#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int price, coogieCash;
	cin >> price >> coogieCash;

	bool coogieCoin[10] = { false };
	for (int i = 9; i >= 0; i--) {
		int curCoin = pow(2, i);
		
		if (price - curCoin >= 0) {
			price -= curCoin;
		}
		if (coogieCash - curCoin >= 0) {
			coogieCash -= curCoin;
			coogieCoin[i] = true;
		}

		if (price == 0 && coogieCash == 0) break;
	}

	if (price == 0) {
		cout << "No thanks";
		return 0;
	}

	for (int i = 9; i >= 0; i--) {
		if (coogieCoin[i]) {
			int curCoin = pow(2, i);
			if (price - curCoin >= 0) {
				price -= curCoin;
			}

			if (price == 0) {
				cout << "Thanks";
				return 0;
			}
		}
	}

	cout << "Impossible";
}