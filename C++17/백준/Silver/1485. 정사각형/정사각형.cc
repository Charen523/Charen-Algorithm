#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

inline int distanceSquared(const pair<int, int>& p1, const pair<int, int>& p2) {
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return dx * dx + dy * dy;
}

bool isSquare(array<pair<int, int>, 4>& points) {
    array<int, 6> distances;
    int idx = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            distances[idx++] = distanceSquared(points[i], points[j]);
        }
    }

    sort(distances.begin(), distances.end());

    return distances[0] > 0 &&
        distances[0] == distances[1] &&
        distances[1] == distances[2] &&
        distances[2] == distances[3] &&
        distances[4] == distances[5] &&
        distances[4] == 2 * distances[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--) {
        array<pair<int, int>, 4> points;

        for (int i = 0; i < 4; ++i) {
            cin >> points[i].first >> points[i].second;
        }

        cout << isSquare(points) << '\n';
    }
}