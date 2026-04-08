#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    vector<int> v(n + 1);
    v[0] = 0; 

    for (int i = 1; i <= n; i++) {
        int num1 = v[i - 1] + 1;
        int num2 = i < 2 ? INT_MAX : v[i - 2] + 1;
        int num5 = i < 5 ? INT_MAX : v[i - 5] + 1;
        int num7 = i < 7 ? INT_MAX : v[i - 7] + 1;

        v[i] = min(min(num1, num2), min(num5, num7));
    }
	
    cout << v[n];
	return 0;
}