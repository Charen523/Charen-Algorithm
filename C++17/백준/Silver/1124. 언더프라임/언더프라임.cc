#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;

    vector<int> spf(B + 1, 0);
    for (int i = 2; i <= B; i++) {
        if (spf[i] == 0) {
            for (int j = i; j <= B; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
        }
    }

    vector<int> factorCount(B + 1, 0);
    for (int i = 2; i <= B; i++) {
        factorCount[i] = factorCount[i / spf[i]] + 1;
    }

    vector<bool> isPrime(B + 1, true);
    if (B >= 0) isPrime[0] = false;
    if (B >= 1) isPrime[1] = false;
    for (int i = 2; i * i <= B; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= B; j += i) {
            isPrime[j] = false;
        }
    }

    int answer = 0;
    for (int i = A; i <= B; i++) {
        if (isPrime[factorCount[i]]) {
            answer++;
        }
    }

    cout << answer;
    return 0;
}