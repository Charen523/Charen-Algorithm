#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    unordered_set<int> sums;

    vector<int> extended(elements.begin(), elements.end());
    extended.insert(extended.end(), elements.begin(), elements.end());

    for (int start = 0; start < n; ++start) {
        int sum = 0;

        for (int length = 1; length <= n; ++length) {
            sum += extended[start + length - 1];
            sums.insert(sum);
        }
    }

    return sums.size();
}