#include <string>
#include <vector>

using namespace std;

const int MAX_BLOCK = 10000000;

int FindBlock(long long num)
{
    if (num == 1) return 0;

    int result = 1;

    for (long long i = 2; i * i <= num; i++) {
        if (num % i != 0) continue;

        long long largeDivisor = num / i;

        if (largeDivisor <= MAX_BLOCK) {
            return static_cast<int>(largeDivisor);
        }

        result = static_cast<int>(i);
    }

    return result;
}

vector<int> solution(long long begin, long long end)
{
    vector<int> answer;

    for (long long i = begin; i <= end; i++) {
        answer.push_back(FindBlock(i));
    }

    return answer;
}