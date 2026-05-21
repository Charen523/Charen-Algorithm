#include <iostream>

using namespace std;

int minNum, maxNum;

int solution(int n, int a, int b)
{
    int answer = 0;
    minNum = 1; maxNum = n + 1;

    bool isEnd = false;
    while (n > 1) {
        n /= 2;
        
        int mid = (minNum + maxNum) / 2;
        if (!isEnd) {
            if (a < mid && b < mid) {
                maxNum = mid;
            }
            else if (a >= mid && b >= mid) {
                minNum = mid;
            }
            else isEnd = true;
        }
        
        if (isEnd) answer++;
    }

    return answer;
}