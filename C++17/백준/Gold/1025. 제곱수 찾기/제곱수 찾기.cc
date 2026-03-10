#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool is_square(long long x) {
    if (x < 0) return false;
    long long r = (long long)sqrt((long double)x);
    return r * r == x || (r + 1) * (r + 1) == x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < M; j++) {
            matrix[i][j] = input[j] - '0';
        }
    }

    long long ans = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int dr = -N; dr <= N; dr++) {
                for (int dc = -M; dc <= M; dc++) {
                    if (dr == 0 && dc == 0) continue;

                    int r = i, c = j;
                    long long num = 0;

                    while (r >= 0 && r < N && c >= 0 && c < M) {
                        num = num * 10 + matrix[r][c];

                        if (is_square(num)) {
                            ans = max(ans, num);
                        }

                        r += dr;
                        c += dc;
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}