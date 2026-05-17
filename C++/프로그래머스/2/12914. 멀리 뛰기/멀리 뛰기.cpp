#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    const int MOD = 1234567;

    if (n == 1) return 1;
    if (n == 2) return 2;

    long long prev2 = 1;
    long long prev1 = 2;
    long long cur = 0;

    for (int i = 3; i <= n; i++) {
        cur = (prev1 + prev2) % MOD;
        prev2 = prev1;
        prev1 = cur;
    }

    return cur;
}