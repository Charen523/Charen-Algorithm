#include <iostream>

using namespace std;

int main() {
	int price, coogieCash;
	cin >> price >> coogieCash;

	bool coogieCoin[10] = { false };
	for (int i = 9; i >= 0; i--) {
		int coinValue = 1 << i;
		
		if (price >= coinValue) {
			price -= coinValue;
		}
		if (coogieCash >= coinValue) {
			coogieCash -= coinValue;
			coogieCoin[i] = true;
		}

		if (price == 0) {
			cout << "No thanks";
			return 0;
		}
	}

	for (int i = 9; i >= 0; i--) {
		if (coogieCoin[i]) {
			int coinValue = 1 << i;
			if (price >= coinValue) {
				price -= coinValue;
			}

			if (price == 0) {
				cout << "Thanks";
				return 0;
			}
		}
	}

	cout << "Impossible";
}