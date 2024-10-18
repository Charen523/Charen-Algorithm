#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    ll P;

    cin >> N >> M >> P;
    bool w = 1;
    for (int i = 0; i < N; ++i) {
        vector<ll> floors(M);
        int k = 0;
        for (int j = 0; j < M; ++j) {
            cin >> floors[j];
            if (floors[j] == -1) {
                k++;
                floors[j] = 0;
            }
        }

        sort(floors.begin(), floors.end());

        for (int j = 0; j < M; ++j) { // 아이템이 아닌 적군들에 대해서만 순회합니다.
            ll f = floors[j];
            //cout << floors[j] << "\n";
            while (k > 0 && P < f) {
                P *= 2;
                k--;
            }

            if (P >= f) {

                P += f;
                //cout << P<<"\n";
            }
            else {
                w = 0;
                break;
            }

        }

        while (k--)
            P *= 2;

        if (P >= 1e18) {
            cout << "0";
            return 0;
        }
        //cout << P << "\n";
    }
    cout << w;
    //cout << "1";
    return 0;
}