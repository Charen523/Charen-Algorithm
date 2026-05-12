#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> countMap;

    for (int size : tangerine) {
        countMap[size]++;
    }

    vector<int> counts;

    for (const auto& [size, count] : countMap) {
        counts.push_back(count);
    }

    sort(counts.begin(), counts.end(), greater<int>());

    int answer = 0;
    int selected = 0;

    for (int count : counts) {
        selected += count;
        answer++;

        if (selected >= k) {
            break;
        }
    }

    return answer;
}