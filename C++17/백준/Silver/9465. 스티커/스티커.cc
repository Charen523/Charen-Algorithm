#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp(vector<vector<int>> v) {
	int n = v[0].size();
	if (n == 0) return 0;
	if (n == 1) return max(v[0][0], v[1][0]);

	vector<vector<int>> d(2, vector<int>(n));

	d[0][0] = v[0][0];
	d[1][0] = v[1][0];

	d[0][1] = d[1][0] + v[0][1];
	d[1][1] = d[0][0] + v[1][1];

	for (int i = 2; i < n; i++) {
		d[0][i] = max(d[1][i - 1], d[1][i - 2]) + v[0][i];
		d[1][i] = max(d[0][i - 1], d[0][i - 2]) + v[1][i];
	}

	return max(d[0][n - 1], d[1][n - 1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		vector<vector<int>> sticker(2, vector<int>(n));
		for (int j = 0; j < n; j++) {
			cin >> sticker[0][j];
		}
		for (int j = 0; j < n; j++) {
			cin >> sticker[1][j];
		}

		cout << dp(sticker) << '\n';
	}

	return 0;
}