#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int n; 
	cin >> n;

	int input;
	vector<int> dp(n, 0);

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> input;
			dp[j] += input;
		}
		
		vector<int> temp = dp;
		for (int j = 1; j <= i; j++) {
			dp[j] = max(temp[j], temp[j - 1]); //부모 중 택1
		}
		
		dp[i + 1] = temp[i]; //부모 고정.
			
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		cin >> input;
		dp[i] += input;
		result = max(result, dp[i]);
	}
    
	cout << result;
	return 0;
}