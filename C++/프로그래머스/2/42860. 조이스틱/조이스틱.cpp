#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findMinCursor() {
    vector<int> v(26); // 0:A, 25:Z

    int lPtr = 1;
    int rPtr = 25;
    int temp = 1;

    while (lPtr <= rPtr) {
        v[lPtr++] = temp;
        v[rPtr--] = temp++;
    }

    return v;
}

int solution(string name) {
    int strSize = name.size();
    int answer = 0;

    vector<int> alphabetCursor = findMinCursor();

    for (int i = 0; i < strSize; i++) {
        int c = name[i] - 'A';
        answer += alphabetCursor[c];
    }

    int minMove = strSize - 1;

    for (int i = 0; i < strSize; i++) {
        int next = i + 1;

        while (next < strSize && name[next] == 'A') {
            next++;
        }

        int moveRightThenLeft = i * 2 + (strSize - next);
        int moveLeftThenRight = i + (strSize - next) * 2;

        minMove = min(minMove, moveRightThenLeft);
        minMove = min(minMove, moveLeftThenRight);
    }

    answer += minMove;

    return answer;
}