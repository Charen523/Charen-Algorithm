#include <iostream>
using namespace std;
using ll = long long;

ll mul(ll a, ll b, ll mod) {
    ll result = 0;
    a %= mod;
    while (b) {
        if (b & 1) result = (result + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return result;
}

ll power(ll a, ll b, ll mod) {
    ll result = 1;
    a %= mod;
    while (b) {
        if (b & 1) result = mul(result, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return result;
}

bool miller(ll n, ll a) {
    if (n % a == 0) return false;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    ll t = power(a, d, n);
    if (t == 1 || t == n - 1) return true;
    while (d != n - 1) {
        t = mul(t, t, n);
        d *= 2;
        if (t == n - 1) return true;
        if (t == 1) return false;
    }
    return false;
}

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 || n == 23 || n == 29) return true;
    if (n % 2 == 0) return false;

    for (ll a : {2, 3, 5, 7, 11}) {
        if (!miller(n, a)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        if (n <= 2) {
            cout << 2 << '\n';
            continue;
        }
        if (n % 2 == 0) ++n;
        while (true) {
            if (isPrime(n)) {
                cout << n << '\n';
                break;
            }
            n += 2;
        }
    }

    return 0;
}