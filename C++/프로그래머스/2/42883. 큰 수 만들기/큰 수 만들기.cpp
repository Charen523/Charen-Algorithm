#include <string>
#include <string_view>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer;
    string_view view = number;

    int target_length = number.size() - k;

    while (k > 0 && answer.size() < target_length) {
        string_view sub = view.substr(0, k + 1);

        auto it = max_element(sub.begin(), sub.end());
        int index = it - sub.begin();

        answer += *it;
        view = view.substr(index + 1);
        k -= index;
    }

    int remaining = target_length - answer.size();
    answer.append(view.begin(), view.begin() + remaining);

    return answer;
}