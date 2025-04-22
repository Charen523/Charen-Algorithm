#include <iostream>
#include <vector>
using namespace std;

int solve(int N) {
    vector<bool> removed(N, false); // 제거 여부 추적
    int idx = 0;    // 현재 위치
    int remain = N; // 남은 카드 수
    bool drop = true; // true면 버리고, false면 뒤로

    while (remain > 1) {
        // 제거되지 않은 카드만 센다
        if (!removed[idx]) {
            if (drop) {
                removed[idx] = true;
                remain--;
            }
            drop = !drop;
        }

        // 다음 인덱스로 순환
        idx = (idx + 1) % N;
    }

    // 마지막 남은 카드 찾기
    for (int i = 0; i < N; ++i) {
        if (!removed[i]) return i + 1;
    }
    return -1; // 이론상 도달 불가
}

int main() {
    int N;
    cin >> N;
    cout << solve(N) << endl;
    return 0;
}
