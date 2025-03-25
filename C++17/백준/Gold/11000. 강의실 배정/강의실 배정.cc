#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, bool>> v;
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		v.push_back({ s, true });
		v.push_back({ t, false });
	}
	sort(v.begin(), v.end());

	int maxResult = 0;
	int temp = 0;
	for (auto [a, b] : v) {
		if (b) {
			temp++;
			maxResult = max(temp, maxResult);
		}
		else {
			temp--;
		}
	}
	cout << maxResult;
	return 0;
}