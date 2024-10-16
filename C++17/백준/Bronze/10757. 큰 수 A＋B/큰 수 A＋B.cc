#include <iostream>
#include <string>
using namespace std;

// 두 문자열로 표현된 숫자를 더하는 함수
string addBigNumbers(string A, string B) {
    string result = "";  // 결과를 저장할 문자열
    int carry = 0;  // 올림수를 저장할 변수
    int a_len = A.length() - 1;
    int b_len = B.length() - 1;

    // A와 B의 끝자리부터 계산
    while (a_len >= 0 || b_len >= 0 || carry > 0) {
        int a_digit = (a_len >= 0) ? A[a_len--] - '0' : 0;
        int b_digit = (b_len >= 0) ? B[b_len--] - '0' : 0;
        int sum = a_digit + b_digit + carry;
        carry = sum / 10;
        result = char(sum % 10 + '0') + result;
    }

    return result;
}

int main() {
    string A, B;
    // A와 B 입력받기
    cin >> A >> B;

    // 결과 출력
    cout << addBigNumbers(A, B) << endl;

    return 0;
}