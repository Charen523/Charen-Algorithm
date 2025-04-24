#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> q; // {index, priority}
        priority_queue<int> pq;  // 중요도 최대 힙

        for (int i = 0; i < n; ++i) {
            int p;
            cin >> p;
            q.push({i, p});
            pq.push(p);
        }

        int count = 0;
        while (!q.empty()) {
            int idx = q.front().first;
            int pri = q.front().second;
            q.pop();

            if (pri == pq.top()) {
                ++count;
                pq.pop();
                if (idx == m) {
                    cout << count << '\n';
                    break;
                }
            } else {
                q.push({idx, pri});
            }
        }
    }

    return 0;
}
