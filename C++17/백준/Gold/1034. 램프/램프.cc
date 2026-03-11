#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct RowInfo {
    int patternCount = 1;
    int zeroCount = 0;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;
    unordered_map<string, RowInfo> rows;

    for (int i = 0; i < N; i++) {
        string s; cin >> s;

        if (rows.find(s) != rows.end()) {
            rows[s].patternCount++;
            continue;
        }

        RowInfo newInfo;
        for (int j = 0; j < M; j++) {
            if (s[j] == '0') newInfo.zeroCount++;
        }

        rows.insert({s, newInfo});
    }

    int K; cin >> K;

    int result = 0;
    for (auto& r : rows) {
        RowInfo info = r.second;
        if (info.zeroCount > K) continue;
        if ((K - info.zeroCount) % 2 != 0) continue;

        result = max(result, info.patternCount);
    }

    cout << result;
    return 0;
}