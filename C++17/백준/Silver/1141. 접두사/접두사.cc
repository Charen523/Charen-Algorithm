#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPrefix(const string& a, const string& b) {
    if (a.size() > b.size()) {
        return false;
    }

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        if (a.size() != b.size()) {
            return a.size() > b.size();
        }
        return a < b;
    });

    vector<string> selected;
    int answer = 0;

    for (const string& word : words) {
        bool is_prefix = false;

        for (const string& s : selected) {
            if (IsPrefix(word, s)) {
                is_prefix = true;
                break;
            }
        }

        if (!is_prefix) {
            selected.push_back(word);
            ++answer;
        }
    }

    cout << answer << '\n';
    return 0;
}