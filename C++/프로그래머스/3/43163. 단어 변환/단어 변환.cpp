#include <string>
#include <vector>
#include <queue>

using namespace std;

bool canChange(const string& a, const string& b) {
    int diff = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            diff++;

            if (diff > 1) {
                return false;
            }
        }
    }

    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q;
    vector<bool> visited(words.size(), false);

    q.push({begin, 0});

    while (!q.empty()) {
        string current = q.front().first;
        int count = q.front().second;
        q.pop();

        if (current == target) {
            return count;
        }

        for (int i = 0; i < words.size(); i++) {
            if (visited[i]) {
                continue;
            }

            if (canChange(current, words[i])) {
                visited[i] = true;
                q.push({words[i], count + 1});
            }
        }
    }

    return 0;
}