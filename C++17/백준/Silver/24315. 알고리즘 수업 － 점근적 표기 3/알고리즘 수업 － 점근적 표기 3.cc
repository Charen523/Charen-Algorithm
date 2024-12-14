#include <iostream>
using namespace std;

int main() {
    int a1, a0, c1, c2, N;

    // 입력
    cin >> a1 >> a0;
    cin >> c1 >> c2;
    cin >> N;

    // 반복문 및 조건 처리
    bool valid = true;
    for (int i = N; i <= 100; i++) {
        if (!(c1 * i <= a1 * i + a0 && a1 * i + a0 <= c2 * i)) {
            cout << 0 << endl;
            valid = false;
            break;
        }
    }

    if (valid) {
        cout << 1 << endl;
    }

    return 0;
}
