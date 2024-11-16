#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> servers;

bool isValid(long long mid, long long halfSum) {
    long long activated = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            activated += min((long long)servers[i][j], mid);
            if (activated >= halfSum) return true;
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

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> servers[i][j];
            totalSum += servers[i][j];
            maxHeight = max(maxHeight, (long long)servers[i][j]);
        }
    }

    long long halfSum = (totalSum + 1) / 2;

    int left = 1, right = maxHeight, result = maxHeight;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (isValid(mid, halfSum)) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1; 
        }
    }

    cout << result << "\n";

    return 0;
}
