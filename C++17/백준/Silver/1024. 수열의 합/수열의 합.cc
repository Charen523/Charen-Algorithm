#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l; cin >> n >> l;
    //합 : n, 길이 최소 L인 연속된 0 ~ 정수 리스트.
    //가우스 : 첫 + 끝 * 연속된수 길이 / 2.

    for (double i = l; i <= 100; i++) {
        double sum = n / i * 2;
        if (sum != (int)sum) continue;

        double delta = i / 2 - 0.5;
        sum /= 2;
        double start = sum - delta;
        double end = sum + delta;
        if (start != (int)start) continue;
        if (start < 0) continue;

        for (int j = start; j <= end; j++) {
            cout << j << ' ';
        }
        return 0;
    }

    cout << -1;
    return 0;
}