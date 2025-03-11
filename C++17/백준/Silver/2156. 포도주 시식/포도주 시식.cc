#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);	
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> red_wine(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> red_wine[i];
    }

    vector<int> dp(n + 1, 0);

    dp[1] = red_wine[1];
    if (n >= 2)
        dp[2] = red_wine[1] + red_wine[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = max({ 
            dp[i - 1],
            dp[i - 2] + red_wine[i],
            dp[i - 3] + red_wine[i - 1] + red_wine[i]
        });
    }

    cout << dp[n];

    return 0;
}
