#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, T;
vector<int> time_req, page_cnt;
int dp[101][366];

int solve(int idx, int days_left) {
    if (idx == N) return 0;
    int& ret = dp[idx][days_left];
    if (ret != -1) return ret;

    ret = solve(idx + 1, days_left);
    if (days_left >= time_req[idx])
        ret = max(ret, solve(idx + 1, days_left - time_req[idx]) + page_cnt[idx]);

    return ret;
}

int main() {
    cin >> T >> N;
    time_req.resize(N);
    page_cnt.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> time_req[i] >> page_cnt[i];
    fill(&dp[0][0], &dp[100][366], -1);
    cout << solve(0, T);
    return 0;
}
