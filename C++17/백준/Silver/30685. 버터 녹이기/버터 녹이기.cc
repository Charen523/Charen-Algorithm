#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int butterCount;
    cin >> butterCount;

    vector<pair<ll, ll>> butterSpread(butterCount);
    for (int i = 0; i < butterCount; i++) {
        cin >> butterSpread[i].first >> butterSpread[i].second;
    }

    sort(butterSpread.begin(), butterSpread.end());

    ll l = 0, r = 1e9;
    while (l < r) {
        ll m = (l + r + 1) >> 1; // 중간 값
        bool canSeparate = true;

        for (int i = 0; i < butterCount - 1; i++) {
            ll x = butterSpread[i].first + min(butterSpread[i].second / 2, m);
            ll y = butterSpread[i + 1].first - min(butterSpread[i + 1].second / 2, m);
            if (x >= y) {
                canSeparate = false;
                break;
            }
        }

        if (canSeparate)
            l = m;
        else
            r = m - 1;
    }

    if (l >= 1e9) {
        cout << "forever";
    } else {
        cout << l;
    }

    return 0;
}
