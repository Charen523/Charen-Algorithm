#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long dp[91][2] = {0};  // 최대 90자리 이친수, long long으로 선언

    // 초기값 설정
    dp[1][0] = 0;
    dp[1][1] = 1;

    // DP 점화식 계산
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    // 결과 출력
    cout << dp[N][0] + dp[N][1] << endl;

    return 0;
}
