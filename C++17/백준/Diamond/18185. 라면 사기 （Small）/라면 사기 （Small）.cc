#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);	
    cin.tie(0);

    int n; 
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && i + 2 < n && v[i + 1] > v[i + 2]) {
            int two = min(v[i], v[i + 1] - v[i + 2]);
            v[i] -= two;
            v[i + 1] -= two;
            result += 5 * two;
        }

        if (i + 1 < n && i + 2 < n) {
            int three = min({v[i], v[i + 1], v[i + 2]});
            v[i] -= three;
            v[i + 1] -= three;
            v[i + 2] -= three;
            result += 7 * three;
        }

        if (i + 1 < n) {
            int two = min(v[i], v[i + 1]);
            v[i] -= two;
            v[i + 1] -= two;
            result += 5 * two;
        }

        result += 3 * v[i];
        v[i] = 0;
    }

    cout << result << '\n';
    return 0;
}