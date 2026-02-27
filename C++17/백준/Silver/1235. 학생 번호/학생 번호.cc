#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; i++) cin >> s[i];

    int L = (int)s[0].size();

    for (int k = 1; k <= L; k++) {
        unordered_set<string> seen;
        seen.reserve(N * 2);

        for (int i = 0; i < N; i++) {
            seen.insert(s[i].substr(L - k, k));
        }

        if ((int)seen.size() == N) {
            cout << k;
            return 0;
        }
    }

    cout << L;
    return 0;
}