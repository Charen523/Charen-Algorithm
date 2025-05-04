#include <iostream>
#include <numeric> // std::lcm
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int maxYear = lcm(M, N);
		bool found = false;

		for (int k = 0; x + k * M <= maxYear; ++k) {
			int year = x + k * M;
			if ((year - y) % N == 0) {
				cout << year << '\n';
				found = true;
				break;
			}
		}

		if (!found) cout << -1 << '\n';
	}

	return 0;
}