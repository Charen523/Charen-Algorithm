#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 큰 수를 문자열 벡터로 곱하는 함수
void multiply(vector<int>& result, int num) {
    int carry = 0;
    for (int i = 0; i < result.size(); ++i) {
        int temp = result[i] * num + carry;
        result[i] = temp % 10;
        carry = temp / 10;
    }

    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }
}

int countTrailingZeros(const vector<int>& result) {
    int count = 0;
    for (int i = 0; i < result.size(); ++i) {
        if (result[i] == 0) count++;
        else break;
    }
    return count;
}

int main() {
    int N;
    cin >> N;

    vector<int> result = {1}; // 초기값 1

    for (int i = 2; i <= N; ++i) {
        multiply(result, i);
    }

    // 뒤에서부터 0의 개수 세기
    int zeroCount = countTrailingZeros(result);
    cout << zeroCount << endl;

    return 0;
}