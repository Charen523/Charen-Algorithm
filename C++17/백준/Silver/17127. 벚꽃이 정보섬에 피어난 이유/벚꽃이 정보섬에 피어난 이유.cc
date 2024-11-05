#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 특정 구간의 곱을 구하는 함수
int product(const vector<int>& trees, int start, int end) {
    int result = 1;
    for (int i = start; i <= end; i++) {
        result *= trees[i];
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> trees(N);
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    int maxResult = 0;

    // 가능한 모든 세 개의 분할 위치를 선택
    for (int i = 1; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                // 네 구간의 곱을 구하고 합을 계산
                int sum = product(trees, 0, i - 1)
                    + product(trees, i, j - 1)
                    + product(trees, j, k - 1)
                    + product(trees, k, N - 1);
                maxResult = max(maxResult, sum);
            }
        }
    }

    cout << maxResult << '\n';
    return 0;
}
