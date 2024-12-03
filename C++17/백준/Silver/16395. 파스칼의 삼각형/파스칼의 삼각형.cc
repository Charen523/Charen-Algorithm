#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long long> current(n + 1, 0);
    current[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = i; j >= 2; j--) {
            current[j] = current[j - 1] + current[j];
        }
    }

    cout << current[k];
}