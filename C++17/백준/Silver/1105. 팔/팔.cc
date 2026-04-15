#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string L, R;
    cin >> L >> R;

    if (L.length() != R.length()) {
        cout << 0;
        return 0;
    }

    int count = 0;
    for (int i = 0; i < (int)L.length(); i++) {
        if (L[i] != R[i]) {
            break;
        }

        if (L[i] == '8') {
            count++;
        }
    }

    cout << count;
    return 0;
}