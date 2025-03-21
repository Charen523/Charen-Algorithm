#include <iostream>
using namespace std;
const int MOD = 1000000007;

struct Matrix {
    long long mat[2][2];

    Matrix operator*(const Matrix& other) const {
        Matrix res = {0};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

Matrix power(Matrix base, long long exp) {
    Matrix res = {{{1, 0}, {0, 1}}};  // 단위 행렬
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = res * base;
        }
        base = base * base;
        exp /= 2;
    }
    return res;
}

long long fibonacci(long long n) {
    if (n == 0) return 0;
    Matrix base = {{{1, 1}, {1, 0}}};
    Matrix res = power(base, n - 1);
    return res.mat[0][0];  // F(n)
}

int main() {
    long long n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}