#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<string>> pictures(N, vector<string>(5));

    // 그림 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> pictures[i][j];
        }
    }

    int minDiff = INT_MAX;
    int pic1 = 0, pic2 = 0;

    // 모든 그림 쌍을 비교
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int diff = 0;

            // 그림 i와 그림 j의 각 위치 비교
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 7; col++) {
                    if (pictures[i][row][col] != pictures[j][row][col]) {
                        diff++;
                    }
                }
            }

            // 최소 차이 업데이트
            if (diff < minDiff) {
                minDiff = diff;
                pic1 = i + 1;
                pic2 = j + 1;
            }
        }
    }

    cout << pic1 << " " << pic2 << endl;
    return 0;
}
