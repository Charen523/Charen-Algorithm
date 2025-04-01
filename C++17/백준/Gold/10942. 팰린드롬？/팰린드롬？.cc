#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

struct pair_hash {
	size_t operator()(const pair<int, bool>& p) const {
		return hash<int>()(p.first) ^ (hash<bool>()(p.second) << 1);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int m; cin >> m;
	unordered_map<pair<int, bool>, int, pair_hash> dp;

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		s--; e--;

		int numerator = s + e;
		bool is_half = (numerator % 2 != 0);
		int tempCount = (e - s + 2) / 2;

		pair<int, bool> key = { numerator, is_half };

		auto it = dp.find(key);
		int c = (it == dp.end()) ? 0 : it->second;

		if (c < tempCount) {
			int lp, rp;

			if (!is_half) {
				int mid = numerator / 2;
				lp = mid - c;
				rp = mid + c;
			}
			else {
				int midL = numerator / 2;
				int midR = numerator / 2 + 1;
				lp = midL - c;
				rp = midR + c;
			}

			while (lp >= 0 && rp < n && v[lp] == v[rp]) {
				c++;
				lp--; rp++;
			}
			dp[key] = c;
		}

		if (dp[key] >= tempCount) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}

	return 0;
}