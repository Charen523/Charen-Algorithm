#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<vector<int>> g(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool b;
			cin >> g[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][k] == 1 && g[k][j] == 1)
					g[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << g[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}