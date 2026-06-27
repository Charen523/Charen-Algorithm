#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int n = citations.size();

    sort(citations.begin(), citations.end());

    int min = 0;
    int max = n;
    int answer = 0;

    while (min <= max) {
        int h = (min + max) / 2;
        int idx = n - h;

        // h편 이상이 h번 이상 인용되었는가?
        if (h == 0 || citations[idx] >= h) {
            answer = h;
            min = h + 1;   // 더 큰 h도 가능한지 확인
        }
        else {
            max = h - 1;   // h가 너무 큼
        }
    }

    return answer;
}