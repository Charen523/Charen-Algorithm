#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> lis;
    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(lis.begin(), lis.end(), v[i]); 
        if (pos == lis.end()) {
            lis.push_back(v[i]);
        }
        else {
            *pos = v[i]; 
        }
    }

    cout << lis.size(); 
}