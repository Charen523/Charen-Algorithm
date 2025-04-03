#include <iostream>
#include <deque>
#include <vector>
using namespace std;

const int MAX = 100001;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> dist(MAX, 1e9);
    deque<int> dq;

    dist[n] = 0;
    dq.push_back(n);

    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();

        if (cur * 2 < MAX && dist[cur * 2] > dist[cur]) {
            dist[cur * 2] = dist[cur];
            dq.push_front(cur * 2);
        }

        if (cur - 1 >= 0 && dist[cur - 1] > dist[cur] + 1) {
            dist[cur - 1] = dist[cur] + 1;
            dq.push_back(cur - 1);
        }

        if (cur + 1 < MAX && dist[cur + 1] > dist[cur] + 1) {
            dist[cur + 1] = dist[cur] + 1;
            dq.push_back(cur + 1);
        }
    }

    cout << dist[k];
    return 0;
}