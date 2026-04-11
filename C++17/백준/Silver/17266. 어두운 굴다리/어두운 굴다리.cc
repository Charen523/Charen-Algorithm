#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> x(M);
    for (int i = 0; i < M; i++) {
        cin >> x[i];
    }

    int result = max(x[0], N - x[M - 1]);

    for (int i = 1; i < M; i++) {
        int gap = x[i] - x[i - 1];
        result = max(result, (gap + 1) / 2);
    }

    cout << result;
    return 0;
}