#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int k = 0; k < T; k++) {
        int H, I;
        cin >> H >> I;

        vector<vector<int>> parkTower(H, vector<int>(I));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < I; j++) {
                cin >> parkTower[i][j];
            }
        }

        vector<pair<int, pair<int, int>>> cars;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < I; j++) {
                if (parkTower[i][j] != -1) {
                    cars.push_back({ parkTower[i][j], { i, j } });
                }
            }
        }

        sort(cars.begin(), cars.end());

        vector<int> currentPos(H, 0);
        int result = 0;

        for (int i = 0; i < cars.size(); i++) {
            int floor = cars[i].second.first;
            int pos = cars[i].second.second;

            result += floor * 20;

            int dist = abs(currentPos[floor] - pos);
            result += min(dist, I - dist) * 5;

            currentPos[floor] = pos;
        }

        cout << result << '\n';
    }

    return 0;
}