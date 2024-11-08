#include <iostream>
#include <string>
using namespace std;

long long getRemainder(const string& dividend, int system, string divisor) {
    long long remainder = 0;

    long long intDivisor = 0;
    int base = 1;
    for (int i = divisor.size() - 1; i >= 0; i--) {
        intDivisor += ((divisor[i]) - '0') * base;
        base *= system;
    }

    for (char digit : dividend) {
        remainder = (remainder * system + (digit - '0')) % intDivisor;
    }

    return remainder;
}

string toBase(long long num, int base) {
    if (num == 0) return "0";
    string result;
    while (num > 0) {
        result = char('0' + num % base) + result;
        num /= base;
    }
    return result;
}

int main() {
    string result = "";

    while (true) {
        long long system;
        string dividend, divisor;
        cin >> system;
        if (system == 0) break;
        cin >> dividend >> divisor;

        int remainder = getRemainder(dividend, system, divisor);

        result += toBase(remainder, system) + "\n";
    }
    cout << result;
}
