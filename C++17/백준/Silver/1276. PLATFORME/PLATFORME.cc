#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Bridge
{
    int y;
    int x1;
    int x2;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Bridge> bridges(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bridges[i].y >> bridges[i].x1 >> bridges[i].x2;
    }

    sort(bridges.begin(), bridges.end(), [](const Bridge& a, const Bridge& b) {
        return a.y < b.y;
    });

    vector<int> height(10001, 0);
    int answer = 0;

    for (const Bridge& bridge : bridges)
    {
        answer += bridge.y - height[bridge.x1];
        answer += bridge.y - height[bridge.x2 - 1];

        for (int x = bridge.x1; x <= bridge.x2 - 1; x++)
        {
            height[x] = bridge.y;
        }
    }

    cout << answer;
    return 0;
}