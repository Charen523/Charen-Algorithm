#include <iostream>
using namespace std;

bool IsInside(int px, int py, int cx, int cy, int r) {
    long long dx = px - cx;
    long long dy = py - cy;
    long long rr = 1LL * r * r;
    return dx * dx + dy * dy < rr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n;
        cin >> n;

        int answer = 0;

        while (n--) {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            bool startInside = IsInside(x1, y1, cx, cy, r);
            bool endInside = IsInside(x2, y2, cx, cy, r);

            if (startInside != endInside) {
                answer++;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}