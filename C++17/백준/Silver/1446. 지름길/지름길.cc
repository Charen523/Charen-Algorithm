#include <iostream>
#include <vector>
using namespace std;

struct Shortcut {
    int e;
    int l;
};

static inline int Min(int a, int b) { return (a < b) ? a : b; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;

    vector<vector<Shortcut>> byStart(D + 1);
    for (int i = 0; i < N; i++) {
        int s, e, l;
        cin >> s >> e >> l;
        if (s < 0 || s > D) continue;
        if (e < 0 || e > D) continue;
        if (l >= e - s) continue;
        byStart[s].push_back({e, l});
    }

    const int INF = 1000000000;
    vector<int> dist(D + 1, INF);
    dist[0] = 0;

    for (int i = 0; i < D; i++) {
        dist[i + 1] = Min(dist[i + 1], dist[i] + 1);
        for (const auto& sc : byStart[i]) {
            dist[sc.e] = Min(dist[sc.e], dist[i] + sc.l);
        }
    }

    cout << dist[D];
    return 0;
}