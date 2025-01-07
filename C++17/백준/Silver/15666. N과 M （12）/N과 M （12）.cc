#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
vector<int> comb;

void Solve(vector<int> v, int idx) {
	if (comb.size() == m) {
		for (int i = 0; i < m; i++) {
			cout << comb[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		comb.push_back(v[i]);
		Solve(v, i);
		comb.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	set<int> inputSet;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		inputSet.insert(k);
	}

	vector<int> v(inputSet.begin(), inputSet.end());
	Solve(v, 0);
}