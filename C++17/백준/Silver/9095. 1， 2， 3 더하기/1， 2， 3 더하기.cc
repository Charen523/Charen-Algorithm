#include <iostream>
#include <vector>

using namespace std;

void findCases(vector<int>& container) {

}

int main() {
	int testCase;
	cin >> testCase;

	int max = 0;
	vector<int> input(testCase);
	for (int i = 0; i < testCase; i++) {
		int value;
		cin >> value;
		input[i] = value;
		if (max < value) max = value;
	}

	vector<int> dp(max + 1);
	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= max; i++) {
		dp[i] = dp[i - 1]; //+1
		if (i > 1) { //+2
			dp[i] += dp[i - 2];
		}
		if (i > 2) { //+3
			dp[i] += dp[i - 3];
		}
	}
	
	for (int i = 0; i < testCase; i++) {
		cout << dp[input[i]] << '\n';
	}
}