#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    unordered_map<int, int> left;
    unordered_map<int, int> right;

    for (int t : topping) {
        right[t]++;
    }

    int leftKind = 0;
    int rightKind = right.size();

    for (int i = 0; i < topping.size() - 1; i++) {
        int t = topping[i];

        if (left[t] == 0) {
            leftKind++;
        }
        left[t]++;

        right[t]--;
        if (right[t] == 0) {
            rightKind--;
        }

        if (leftKind == rightKind) {
            answer++;
        }
    }

    return answer;
}