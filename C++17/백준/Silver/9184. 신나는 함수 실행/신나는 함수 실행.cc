#include <iostream>
#include <cstring>
using namespace std;

int dp[51][51][51];

int solve(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		a = 0; b = 0; c = 0;
		return dp[a][b][c] = 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		a = 20; b = 20; c = 20;
		return dp[a][b][c] = solve(20, 20, 20);
	}

    // 이미 계산된 값이 있다면 반환
    if (dp[a][b][c] != -1) {
        return dp[a][b][c];
    }

    if (a < b && b < c) {
        return dp[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
    }

    return dp[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) +
                         solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 배열 초기화
    memset(dp, -1, sizeof(dp));

    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        
        cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << '\n';
    }

    return 0;
}
