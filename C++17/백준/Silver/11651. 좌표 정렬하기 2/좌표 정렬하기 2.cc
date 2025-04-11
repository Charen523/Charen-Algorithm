#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[i] = { x, y };
	}

	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first < b.first;
		else return a.second < b.second;
		});

	for (auto [x, y] : v) {
		cout << x << ' ' << y << '\n';
	}

	return 0;
}