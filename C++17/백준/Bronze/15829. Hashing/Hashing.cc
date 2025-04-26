#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

const ll r = 31;
const ll M = 1234567891;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    ll hashValue = 0;
    ll powR = 1; // r^i

    for (int i = 0; i < n; ++i) {
        int value = s[i] - 'a' + 1;
        hashValue = (hashValue + value * powR) % M;
        powR = (powR * r) % M;
    }

    cout << hashValue << '\n';
    return 0;
}
