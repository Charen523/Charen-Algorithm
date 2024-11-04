#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int C, N;
    cin >> C >> N;

    vector<pair<int, int>> cities(N);
    for (int i = 0; i < N; i++) {
        int cost, customers;
        cin >> cost >> customers;
        cities[i] = {cost, customers};
    }

    // 매우 큰 값으로 초기화 (무한대에 가까운 값)
    const int INF = 1e9;
    vector<int> dp(C + 101, INF);
    dp[0] = 0;

    for (const auto& city : cities) {
        int cost = city.first;
        int customers = city.second;
        
        for (int j = customers; j < dp.size(); j++) {
            dp[j] = min(dp[j], dp[j - customers] + cost);
        }
    }

    // 최소한 C명의 고객을 확보할 수 있는 최솟값을 찾기
    int result = *min_element(dp.begin() + C, dp.end());
    cout << result << '\n';

    return 0;
}
