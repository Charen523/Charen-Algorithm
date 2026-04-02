#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, Y;
    cin >> X >> Y;

    long long Z = Y * 100 / X;

    if (Z >= 99) {
        cout << -1;
        return 0;
    }

    long long left = 1;
    long long right = 1000000000;
    long long answer = -1;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long newZ = (Y + mid) * 100 / (X + mid);

        if (newZ > Z) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer;
    return 0;
}