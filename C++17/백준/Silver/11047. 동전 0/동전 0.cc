#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);
    
	int n; int k;
	cin >> n >> k;
	vector<int> price_value(n);
	for (int i = 0; i < n; i++) {
		cin >> price_value[i];
	}

	reverse(price_value.begin(), price_value.end());
	
	int result = 0, idx = 0;
	while (k > 0) {
		while (price_value[idx] > k) {
			idx++;
		}
		int inc = k / price_value[idx];
		k -= price_value[idx] * inc;
		result += inc;
	}
	cout << result;

	return 0;
}