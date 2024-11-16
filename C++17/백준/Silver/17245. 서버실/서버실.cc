#include <iostream>
#include <vector>
#include <algorithm> // std::max

using namespace std;

// 입력 크기와 서버 데이터를 전역으로 관리
int N;
vector<vector<int>> servers;

bool isValid(long long mid, long long halfSum) {
    long long activated = 0;

    // 각 칸에서 활성화되는 컴퓨터의 수를 누적
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            activated += min((long long)servers[i][j], mid);
            if (activated >= halfSum) return true; // 절반 이상이면 조기 종료
        }
    }
    return activated >= halfSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    servers.assign(N, vector<int>(N));

    long long totalSum = 0;
    long long maxHeight = 0;

    // 입력 및 합 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> servers[i][j];
            totalSum += servers[i][j];
            maxHeight = max(maxHeight, (long long)servers[i][j]);
        }
    }

    // 절반 이상의 컴퓨터가 작동해야 함
    long long halfSum = (totalSum + 1) / 2;

    // 이분 탐색으로 최소 시간을 찾음
    long long left = 1, right = maxHeight, result = maxHeight;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (isValid(mid, halfSum)) {
            result = mid;    // 가능한 경우 더 작은 값 탐색
            right = mid - 1;
        }
        else {
            left = mid + 1;  // 불가능한 경우 더 큰 값 탐색
        }
    }

    cout << result << "\n";

    return 0;
}
