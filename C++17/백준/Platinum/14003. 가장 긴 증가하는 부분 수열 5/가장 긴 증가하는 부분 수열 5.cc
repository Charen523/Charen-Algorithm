#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> dp;
	vector<int> pos(n);
	vector<int> prev(n, -1);
	vector<int> lastIndex;

	for (int i = 0; i < n; i++) {
		int val = v[i];
		auto it = lower_bound(dp.begin(), dp.end(), val);
		int idx = it - dp.begin();

		if (it == dp.end()) {
			dp.push_back(val);
			lastIndex.push_back(i);
		} else {
			*it = val;
			lastIndex[idx] = i;
		}

		pos[i] = idx;
		if (idx > 0)
			prev[i] = lastIndex[idx - 1];
	}

	int len = dp.size();
	cout << len << '\n';

	vector<int> lis;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (pos[i] == len - 1) {
			cur = i;
			break;
		}
	}

	while (cur != -1) {
		lis.push_back(v[cur]);
		cur = prev[cur];
	}
	reverse(lis.begin(), lis.end());

	for (int x : lis)
		cout << x << ' ';
	cout << '\n';

	return 0;
}
