#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int N = static_cast<int>(s.size());
    vector<int> prefix(N + 1, 0);

    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + (s[i] - '0');
    }

    int result = 0;

    for (int len = 2; len <= N; len += 2) {
        int half = len / 2;

        for (int start = 0; start + len <= N; start++) {
            int leftSum = prefix[start + half] - prefix[start];
            int rightSum = prefix[start + len] - prefix[start + half];

            if (leftSum == rightSum) {
                result = len;
            }
        }
    }

    cout << result;
    return 0;
}