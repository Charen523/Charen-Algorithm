#include <iostream>
#include <vector>

using namespace std;

long long binomialCoefficient(int n, int k) {
    vector<long long> C(k + 1, 0);
    C[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = min(i, k); j > 0; --j) {
            C[j] = C[j] + C[j - 1];
        }
    }

    return C[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    cout << binomialCoefficient(n, k) << '\n';
}