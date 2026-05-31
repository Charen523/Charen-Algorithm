#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    long long r1Sq = 1LL * r1 * r1;
    long long r2Sq = 1LL * r2 * r2;

    for (long long x = 1; x <= r2; x++) {
        long long xSq = x * x;

        long long maxY = floor(sqrt(r2Sq - xSq));

        long long minYSq = r1Sq - xSq;
        long long minY = 0;

        if (minYSq > 0) {
            minY = ceil(sqrt(minYSq));
        }

        answer += maxY - minY + 1;
    }

    return answer * 4;
}