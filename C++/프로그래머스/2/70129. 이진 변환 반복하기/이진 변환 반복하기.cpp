#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ToBinary(int num) {
    if (num == 0) {
        return "0";
    }

    string result = "";

    while (num > 0) {
        result = char(num % 2 + '0') + result;
        num /= 2;
    }

    return result;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);

    while (s != "1") {
        int zeros = count(s.begin(), s.end(), '0');
        int ones = s.size() - zeros;

        answer[0]++;
        answer[1] += zeros;

        s = ToBinary(ones);
    }

    return answer;
}