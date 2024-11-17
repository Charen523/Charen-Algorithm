#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, l, w, h;

bool isValid(long double cubeSize)
{
    long long _l = l / cubeSize;
    long long _w = w / cubeSize;
    long long _h = h / cubeSize;

    long long boxCount = _l * _w * _h;
    return boxCount >= n;
}

int main()
{
    cin >> n >> l >> w >> h;

    long double left = 0, right = min(l, min(w, h));
    long double answer = 0;
    while (right - left > 1e-9)
    {
        long double mid = (left + right) / 2;

        if (isValid(mid))
        {
            left = mid;
            answer = mid;
        }
        else right = mid;
    }
    cout.precision(30);
    cout << answer;
}