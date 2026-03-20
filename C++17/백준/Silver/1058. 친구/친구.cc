#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> friends(N);
    for (int i = 0; i < N; i++) {
        cin >> friends[i];
    }

    int result = 0;

    for (int i = 0; i < N; i++) {
        int count = 0;

        for (int j = 0; j < N; j++) {
            if (i == j) continue;

            if (friends[i][j] == 'Y') {
                count++;
                continue;
            }

            for (int k = 0; k < N; k++) {
                if (friends[i][k] == 'Y' && friends[k][j] == 'Y') {
                    count++;
                    break;
                }
            }
        }

        if (result < count) {
            result = count;
        }
    }

    cout << result;
    return 0;
}