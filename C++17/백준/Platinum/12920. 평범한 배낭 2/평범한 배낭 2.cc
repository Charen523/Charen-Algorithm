#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; 
	cin >> n >> m;

	vector<pair<int, int>> items;
	for (int i = 0; i < n; i++) {
		int v, c, k;
		cin >> v >> c >> k;
		for (int i = 1; k > 0; i <<= 1) {
			int count = min(i, k);
			items.push_back({v * count, c * count});
			k -= count;
		}
	}

	vector<int> dp(m + 1, 0);
	for (auto [weight, value] : items) {
		for (int j = m; j >= weight; j--) {
			dp[j] = max(dp[j], dp[j - weight] + value);
		}
	}

	cout << *max_element(dp.begin(), dp.end());

	return 0;
}