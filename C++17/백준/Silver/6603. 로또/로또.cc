#include <iostream>
#include <vector>
using namespace std;

vector<int> result;
void count_case(const vector<int>& v, int idx) {
	if (result.size() == 6) {
		for (int i = 0; i < 6; i++)
			cout << result[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		result.push_back(v[i]);
		count_case(v, i + 1);
		result.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int k; cin >> k;
		if (k == 0) break;

		vector<int> v(k);
		for (int i = 0; i < k; i++) {
			cin >> v[i];
		}
		result.clear();
		count_case(v, 0);
		cout << '\n';
	}

	return 0;
}