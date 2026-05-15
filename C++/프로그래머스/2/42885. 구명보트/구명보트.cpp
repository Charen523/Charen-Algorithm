#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit)
{
    sort(people.begin(), people.end());

    int left = 0;
    int right = people.size() - 1;
    int answer = 0;

    while (left <= right)
    {
        if (people[left] + people[right] <= limit)
        {
            left++;
        }

        right--;
        answer++;
    }

    return answer;
}