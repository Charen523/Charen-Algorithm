#include <iostream>
using namespace std;

int mod = 9901;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int dp0 = 1, dp1 = 1, dp2 = 1; // i = 1

    for (int i = 2; i <= n; i++) {
        int ndp0 = (dp0 + dp1 + dp2) % mod;
        int ndp1 = (dp0 + dp2) % mod;
        int ndp2 = (dp0 + dp1) % mod;

        dp0 = ndp0;
        dp1 = ndp1;
        dp2 = ndp2;
    }

    cout << (dp0 + dp1 + dp2) % mod;
    return 0;
}