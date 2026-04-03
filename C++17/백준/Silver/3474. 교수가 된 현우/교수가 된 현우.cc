#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long n;
        cin >> n;

        long long result = 0;
        while (n > 0) {
            n /= 5;
            result += n;
        }

        cout << result << '\n';
    }

    return 0;
}