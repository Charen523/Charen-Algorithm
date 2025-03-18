#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(const vector<int>& v) {
	vector<int> arr;

	for (int value : v) {
		auto idx = lower_bound(arr.begin(), arr.end(), value);

		if (idx == arr.end()) {
			arr.push_back(value);
		}
		else {
			*idx = value;
		}
	}

	return arr.size();
}

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << solve(v);
    
	return 0;
}