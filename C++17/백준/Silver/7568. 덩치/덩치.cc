#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    
    vector<pair<int, int>> list(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        list[i] = {x, y};
    }

    
    for (int i = 0; i < n; i++) {
        int rank = 1;
        int x = list[i].first;
        int y = list[i].second;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int _x = list[j].first;
            int _y = list[j].second;

            if (_x > x && _y > y) {
                rank++;
            }
        }
        cout << rank << ' ';
    }


    return 0;
}