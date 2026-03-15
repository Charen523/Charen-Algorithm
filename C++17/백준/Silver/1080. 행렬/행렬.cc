#include <iostream>
#include <vector>
#include <string>
using namespace std;

void flip3x3(vector<string>& mat, int row, int col) {
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            mat[i][j] = (mat[i][j] == '0') ? '1' : '0';
        }
    }
}

bool isSame(const vector<string>& matA, const vector<string>& matB) {
    int N = static_cast<int>(matA.size());
    for (int i = 0; i < N; i++) {
        if (matA[i] != matB[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> matA(N), matB(N);
    for (int i = 0; i < N; i++) {
        cin >> matA[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> matB[i];
    }

    int count = 0;

    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= M - 3; j++) {
            if (matA[i][j] != matB[i][j]) {
                flip3x3(matA, i, j);
                count++;
            }
        }
    }

    if (isSame(matA, matB)) {
        cout << count;
    } else {
        cout << -1;
    }

    return 0;
}