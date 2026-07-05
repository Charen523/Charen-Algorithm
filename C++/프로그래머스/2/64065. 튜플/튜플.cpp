#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<vector<int>> sets;
    vector<int> answer;
    vector<bool> used(100001, false);

    vector<int> current;
    string num = "";

    for (int i = 1; i < s.size() - 1; i++) {
        char c = s[i];

        if (c >= '0' && c <= '9') {
            num += c;
        }
        else {
            if (!num.empty()) {
                current.push_back(stoi(num));
                num = "";
            }

            if (c == '}') {
                sets.push_back(current);
                current.clear();
            }
        }
    }

    sort(sets.begin(), sets.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();
    });

    for (const vector<int>& set : sets) {
        for (int n : set) {
            if (!used[n]) {
                used[n] = true;
                answer.push_back(n);
                break;
            }
        }
    }

    return answer;
}