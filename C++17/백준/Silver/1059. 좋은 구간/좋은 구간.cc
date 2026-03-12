#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L; cin >> L;
    vector<int> S(L);

    for (int i = 0; i < L; i++) cin >> S[i];

    int n; cin >> n;

    sort(S.begin(), S.end());

    for (int x : S) {
        if (x == n) {
            cout << 0;
            return 0;
        }
    }

    int left = 0;
    int right = 1001;

    for (int x : S) {
        if (x < n) left = x;
        if (x > n) {
            right = x;
            break;
        }
    }

    cout << (n - left) * (right - n) - 1;
}