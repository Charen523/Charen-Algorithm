#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> sorted;

    for (int number : numbers) {
        sorted.push_back(to_string(number));
    }

    sort(sorted.begin(), sorted.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });

    if (sorted[0] == "0") {
        return "0";
    }

    string answer = "";
    for (const string& s : sorted) {
        answer += s;
    }

    return answer;
}