#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> coins(n);
    for (int& coin : coins) std::cin >> coin;

    const int INF = INT_MAX - 1; // 오버플로 방지
    std::vector<int> dp(k + 1, INF);
    dp[0] = 0;

    for (int coin : coins) {
        for (int i = coin; i <= k; ++i) {
            if (dp[i - coin] != INF)
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
        }
    }

    std::cout << (dp[k] == INF ? -1 : dp[k]) << '\n';
    return 0;
}