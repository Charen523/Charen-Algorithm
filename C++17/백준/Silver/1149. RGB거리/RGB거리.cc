#include <iostream>
#include <vector>

using namespace std;

struct Color {
	int red;
	int green;
	int blue;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase; cin >> testCase;

	vector<Color> dp(testCase);
	for (int i = 0; i < testCase; i++) {
		cin >> dp[i].red >> dp[i].green >> dp[i].blue;
	}

	for (int i = 1; i < testCase; i++) {
		dp[i].red = dp[i].red + min(dp[i - 1].green, dp[i - 1].blue);
		dp[i].green = dp[i].green + min(dp[i - 1].red, dp[i - 1].blue);
		dp[i].blue = dp[i].blue + min(dp[i - 1].red, dp[i - 1].green);
	}
	int result = min(dp[testCase - 1].red, min(dp[testCase - 1].green, dp[testCase - 1].blue));
	cout << result;
}