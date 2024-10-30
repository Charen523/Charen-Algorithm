#include <iostream>
using namespace std;

// 주어진 숫자를 base 진수로 변환 후 자리수 합 계산
int digitSum(int num, int base) {
    int sum = 0;
    while (num > 0) {
        sum += num % base;  // base로 나눈 나머지를 sum에 더함
        num /= base;         // base로 나눈 몫을 num에 할당
    }
    return sum;
}

int main() {
    // 네 자리 숫자 (1000 ~ 9999) 확인
    for (int i = 1000; i <= 9999; i++) {
        int sum10 = digitSum(i, 10);  // 10진수 자리수 합
        int sum12 = digitSum(i, 12);  // 12진수 자리수 합
        int sum16 = digitSum(i, 16);  // 16진수 자리수 합

        // 모든 자리수 합이 같다면 출력
        if (sum10 == sum12 && sum12 == sum16) {
            cout << i << endl;
        }
    }
    return 0;
}
