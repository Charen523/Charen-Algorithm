#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void back_tracking() {
	if (v.size() == m) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		bool isOk = true;
		for (int j = 0; j < v.size(); j++) {
			if (i == v[j]) {
				isOk = false;
				break;
			}
		}

		if (isOk) {
			v.push_back(i);
			back_tracking();
			v.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	back_tracking();
	return 0;
}