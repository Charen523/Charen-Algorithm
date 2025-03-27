#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, b, c;
    cin >> n >> b >> c;

    vector<int> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];

    ll result = 0;
    for (int i = 0; i < n - 2; i++) {
        int next = i + 1, nnext = i + 2;

        if (c < b && v[next] > v[nnext]) {
            ll m = min(v[i], v[next] - v[nnext]);
            v[i] -= m;
            v[next] -= m;
            result += m * (b + c);
        }

        if (c < b) {
            ll m = min({ v[i], v[next], v[nnext] });
            v[i] -= m;
            v[next] -= m;
            v[nnext] -= m;
            result += m * (b + 2 * c);
        }

        if (c < b) {
            ll m = min(v[i], v[next]);
            v[i] -= m;
            v[next] -= m;
            result += m * (b + c);
        }

        result += v[i] * b;
        v[i] = 0;
    }

    if (n >= 2) {
        int i = n - 2;
        if (c < b) {
            ll m = min(v[i], v[i + 1]);
            v[i] -= m;
            v[i + 1] -= m;
            result += m * (b + c);
        }
        result += v[i] * b;
        result += v[i + 1] * b;
    }
    else {
        result += v[n - 1] * b;
    }

    cout << result << '\n';
    return 0;
}