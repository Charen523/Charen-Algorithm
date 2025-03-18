#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    vector<int> towers(n);
    vector<int> answer(n, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> towers[i];
    }

    stack<pair<int, int>> s;
    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first < towers[i]) {
            s.pop();
        }

        if (!s.empty()) {
            answer[i] = s.top().second + 1;
        }

        s.push({towers[i], i});
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}