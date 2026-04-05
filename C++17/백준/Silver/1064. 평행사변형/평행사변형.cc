#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

double GetDistance(int x1, int y1, int x2, int y2)
{
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    long long cross = 1LL * (bx - ax) * (cy - ay) - 1LL * (by - ay) * (cx - ax);

    if (cross == 0)
    {
        cout << -1.0;
        return 0;
    }

    double ab = GetDistance(ax, ay, bx, by);
    double bc = GetDistance(bx, by, cx, cy);
    double ca = GetDistance(cx, cy, ax, ay);

    double maxLen = max({ab, bc, ca});
    double minLen = min({ab, bc, ca});

    double answer = 2.0 * (maxLen - minLen);

    cout << fixed << setprecision(16) << answer;
    return 0;
}