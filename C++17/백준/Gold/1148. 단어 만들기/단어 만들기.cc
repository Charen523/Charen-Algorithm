#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, int> dictCount;

void GenerateSubsets(
    int idx,
    const vector<pair<char, int>>& letters,
    string& current,
    vector<string>& subsets
) {
    if (idx == (int)letters.size()) {
        int len = (int)current.size();
        if (len >= 4 && len <= 9) {
            subsets.push_back(current);
        }
        return;
    }

    char ch = letters[idx].first;
    int cnt = letters[idx].second;

    GenerateSubsets(idx + 1, letters, current, subsets);

    for (int i = 1; i <= cnt; i++) {
        current.push_back(ch);
        GenerateSubsets(idx + 1, letters, current, subsets);
    }

    for (int i = 1; i <= cnt; i++) {
        current.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        string word;
        cin >> word;
        if (word == "-") break;

        sort(word.begin(), word.end());
        dictCount[word]++;
    }

    while (true) {
        string puzzle;
        cin >> puzzle;
        if (puzzle == "#") break;

        int puzzleCnt[26] = {0};
        for (char ch : puzzle) {
            puzzleCnt[ch - 'A']++;
        }

        vector<pair<char, int>> letters;
        for (int i = 0; i < 26; i++) {
            if (puzzleCnt[i] > 0) {
                letters.push_back({char('A' + i), puzzleCnt[i]});
            }
        }

        vector<string> subsets;
        string current;
        GenerateSubsets(0, letters, current, subsets);

        int appearCount[26] = {0};

        for (const string& subset : subsets) {
            auto it = dictCount.find(subset);
            if (it == dictCount.end()) continue;

            int freq = it->second;

            bool used[26] = {false};
            for (char ch : subset) {
                used[ch - 'A'] = true;
            }

            for (int i = 0; i < 26; i++) {
                if (used[i]) {
                    appearCount[i] += freq;
                }
            }
        }

        int minValue = 1e9;
        int maxValue = -1;

        for (int i = 0; i < 26; i++) {
            if (puzzleCnt[i] > 0) {
                minValue = min(minValue, appearCount[i]);
                maxValue = max(maxValue, appearCount[i]);
            }
        }

        string minLetters;
        string maxLetters;

        for (int i = 0; i < 26; i++) {
            if (puzzleCnt[i] > 0 && appearCount[i] == minValue) {
                minLetters.push_back(char('A' + i));
            }
        }

        for (int i = 0; i < 26; i++) {
            if (puzzleCnt[i] > 0 && appearCount[i] == maxValue) {
                maxLetters.push_back(char('A' + i));
            }
        }

        cout << minLetters << ' ' << minValue << ' '
             << maxLetters << ' ' << maxValue << '\n';
    }

    return 0;
}