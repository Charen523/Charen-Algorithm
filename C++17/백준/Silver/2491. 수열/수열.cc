#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    enum comparison {
        same,
        bigger,
        smaller
    };

    int n;
    cin >> n;
    int prev, next;
    vector<comparison> lines(n - 1);

    cin >> prev;
    for (int i = 0; i < n - 1; i++) {
        cin >> next;
        lines[i] = (next > prev) ? bigger : (next < prev) ? smaller : same;
        prev = next;
    }

    int cur = 0, max_length = 0;

    for (int i = 0; i < n - 1; i++) {
        if (lines[i] != smaller) {
            cur++;
        }
        else {
            max_length = max(max_length, cur);
            cur = 0;
        }
    }
    max_length = max(max_length, cur);

    cur = 0;

    for (int i = 0; i < n - 1; i++) {
        if (lines[i] != bigger) {
            cur++;
        }
        else {
            max_length = max(max_length, cur);
            cur = 0;
        }
    }
    max_length = max(max_length, cur);

    cout << max_length + 1;
    return 0;
}
