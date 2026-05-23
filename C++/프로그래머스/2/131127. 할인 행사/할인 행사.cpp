#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool IsSame(const unordered_map<string, int>& need,
            const unordered_map<string, int>& current)
{
    for (const auto& item : need) {
        const string& name = item.first;
        int count = item.second;

        auto it = current.find(name);
        if (it == current.end() || it->second != count) {
            return false;
        }
    }

    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;

    unordered_map<string, int> need;
    unordered_map<string, int> current;

    for (int i = 0; i < want.size(); i++) {
        need[want[i]] = number[i];
    }

    for (int i = 0; i < discount.size(); i++) {
        current[discount[i]]++;

        if (i >= 10) {
            current[discount[i - 10]]--;

            if (current[discount[i - 10]] == 0) {
                current.erase(discount[i - 10]);
            }
        }

        if (i >= 9 && IsSame(need, current)) {
            answer++;
        }
    }

    return answer;
}