#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, char> codeMap;
    for (int i = 0; i < n; ++i) {
        char ch;
        string code;
        cin >> ch >> code;
        codeMap[code] = ch;
    }

    string encoded;
    cin >> encoded;

    string current;
    for (char bit : encoded) {
        current += bit;
        if (codeMap.count(current)) {
            cout << codeMap[current];
            current.clear();
        }
    }
    cout << '\n';
    return 0;
}
