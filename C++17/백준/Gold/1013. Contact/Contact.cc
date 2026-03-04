#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        int ptr = 0;
        int n = (int)s.size();
        bool isRuined = false;

        while (ptr < n) {
            if (ptr + 1 < n && s[ptr] == '0' && s[ptr + 1] == '1') {
                ptr += 2;
                continue;
            }

            if (ptr + 2 < n && s[ptr] == '1' && s[ptr + 1] == '0' && s[ptr + 2] == '0') {
                ptr += 3;

                while (ptr < n && s[ptr] == '0') ptr++;

                if (ptr >= n || s[ptr] != '1') {
                    isRuined = true;
                    break;
                }

                int ones = 0;
                while (ptr < n && s[ptr] == '1') {
                    ptr++;
                    ones++;
                }

                if (ones >= 2 && ptr < n && s[ptr] == '0' && ptr + 1 < n && s[ptr + 1] == '0') {
                    ptr--;
                }

                continue;
            }

            isRuined = true;
            break;
        }

        cout << (isRuined ? "NO\n" : "YES\n");
    }

    return 0;
}