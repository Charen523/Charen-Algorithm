#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; 
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	
	vector<int> dp(n, 1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (input[i] > input[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << *max_element(dp.begin(), dp.end());
}