#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

    int camera = -30001;

    for (const vector<int>& route : routes) {
        int start = route[0];
        int end = route[1];

        if (camera < start) {
            camera = end;
            answer++;
        }
    }

    return answer;
}