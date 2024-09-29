#include <iostream>
#include <vector>

using namespace std;

void fibonacci(int n, int& zero, int& one) {
    if (n == 0) {
        zero = 1;
    }
    else if (n == 1) {
        one = 1;
    }
    else {
        vector<int> fib(n + 1);
        fib[0] = 0;
        fib[1] = 1;

        for (int i = 2; i <= n; ++i) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        zero = fib[n - 1]; one = fib[n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        int value;
        cin >> value; //0 ~ 40.

        int zero = 0, one = 0;
        fibonacci(value, zero, one);
        cout << zero << ' ' << one << '\n';
    }
}