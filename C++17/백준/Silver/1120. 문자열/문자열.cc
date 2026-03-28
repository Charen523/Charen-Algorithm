#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    cin >> A >> B;

    int answer = static_cast<int>(A.size());

    for (int start = 0; start <= static_cast<int>(B.size() - A.size()); start++) {
        int diff = 0;

        for (int i = 0; i < static_cast<int>(A.size()); i++) {
            if (A[i] != B[start + i]) {
                diff++;
            }
        }

        answer = min(answer, diff);
    }

    cout << answer;
    return 0;
}