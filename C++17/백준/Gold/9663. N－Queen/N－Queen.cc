#include <iostream>
#include <vector>
using namespace std;

int n, result = 0;
vector<bool> col, diag1, diag2;

void solve(int row) {
    if (row == n) {
        result++;
        return;
    }

    for (int c = 0; c < n; c++) {
        if (col[c] || diag1[row + c] || diag2[row - c + n - 1]) continue;

        col[c] = diag1[row + c] = diag2[row - c + n - 1] = true;
        solve(row + 1);
        col[c] = diag1[row + c] = diag2[row - c + n - 1] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    col.resize(n, false);
    diag1.resize(2 * n - 1, false); // ↘ 방향
    diag2.resize(2 * n - 1, false); // ↙ 방향

    solve(0);
    cout << result << '\n';
    return 0;
}
