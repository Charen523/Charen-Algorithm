#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isNumber(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, string> byId;
    unordered_map<string, int> byName;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        byId[i] = s;
        byName[s] = i;
    }

    while (m--) {
        string query;
        cin >> query;
        if (isNumber(query)) {
            cout << byId[stoi(query)] << '\n';
        } else {
            cout << byName[query] << '\n';
        }
    }

    return 0;
}
