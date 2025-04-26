#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    map<int, int> m;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]]++;
    }

    sort(v.begin(), v.end());

    // 산술평균 (소수점 이하 반올림)
    int sum = accumulate(v.begin(), v.end(), 0);
    int avg = (int)round((double)sum / n);

    // 중앙값
    int mid = v[n / 2];

    // 최빈값
    int maxCount = 0;
    vector<int> modes;
    for (auto& [value, count] : m) {
        if (count > maxCount) {
            maxCount = count;
            modes.clear();
            modes.push_back(value);
        } else if (count == maxCount) {
            modes.push_back(value);
        }
    }

    int mode;
    if (modes.size() == 1) {
        mode = modes[0];
    } else {
        sort(modes.begin(), modes.end());
        mode = modes[1]; // 두 번째로 작은 값
    }

    // 범위
    int range = v.back() - v.front();

    // 출력
    cout << avg << '\n';
    cout << mid << '\n';
    cout << mode << '\n';
    cout << range << '\n';

    return 0;
}
