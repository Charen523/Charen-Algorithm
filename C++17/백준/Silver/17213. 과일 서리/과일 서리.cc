#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

ll fact(int s, int e = 1) {
    if (s <= 1) return 1;

    ll result = 1;
    for (int i = s; i >= e; i--) {
        result *= i;
    }
    return result;
}

ll combination(int a, int b) {
    ll result = fact(a, a - b + 1);
    return result / fact(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n; // 1~10 //종류의 수
    int m; cin >> m; // n <= m <= 30 //훔치는 개수

    cout << combination(m - 1, n - 1);

	return 0;
}