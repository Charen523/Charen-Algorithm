#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights)
{
    long long answer = 0;
    unordered_map<int, long long> count;

    sort(weights.begin(), weights.end());

    for (int w : weights)
    {
        answer += count[w];

        if (w * 2 % 3 == 0)
        {
            answer += count[w * 2 / 3];
        }

        if (w % 2 == 0)
        {
            answer += count[w / 2];
        }

        if (w * 3 % 4 == 0)
        {
            answer += count[w * 3 / 4];
        }

        count[w]++;
    }

    return answer;
}