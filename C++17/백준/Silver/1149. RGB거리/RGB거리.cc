#include <iostream>
#include <vector>

using namespace std;

struct Color {
	int R;
	int G;
	int B;

	Color() : R(0), G(0), B(0) {}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase; cin >> testCase;
	
	vector<Color> paintPrice(testCase);
	for (int i = 0; i < testCase; i++) {
		cin >> paintPrice[i].R >> paintPrice[i].G >> paintPrice[i].B;
	}

	vector<vector<int>> dp(testCase, vector<int>(3, 0));
	dp[0][0] = paintPrice[0].R;
	dp[0][1] = paintPrice[0].G;
	dp[0][2] = paintPrice[0].B;

	for (int i = 1; i < testCase; i++) {
		dp[i][0] = paintPrice[i].R + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = paintPrice[i].G + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = paintPrice[i].B + min(dp[i - 1][0], dp[i - 1][1]);
	}

	int result = min(dp[testCase - 1][0], min(dp[testCase - 1][1], dp[testCase - 1][2]));
	cout << result;
}