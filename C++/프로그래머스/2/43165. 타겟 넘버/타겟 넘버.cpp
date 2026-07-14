#include <string>
#include <vector>

using namespace std;

int answer = 0;
int TARGET;

void dfs(const vector<int>& numbers, int index, int sum) {
    if (index == numbers.size()) {
        if (sum == TARGET)
            answer++;
        return;
    }

    dfs(numbers, index + 1, sum + numbers[index]);
    dfs(numbers, index + 1, sum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    TARGET = target;

    dfs(numbers, 0, 0);

    return answer;
}