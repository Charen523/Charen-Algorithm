#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> v; // {값, 원래 인덱스}
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back({x, i});
    }

    sort(v.begin(), v.end()); // 값 오름차순, 같으면 인덱스 오름차순

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        P[v[i].second] = i;
    }

    for (int i = 0; i < N; i++) {
        cout << P[i] << ' ';
    }

    return 0;
}