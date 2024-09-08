#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    vector<int> intArr;
    stringstream ss(s);
    string token;

    while (getline(ss, token, ' ')) {
        intArr.push_back(stoi(token));
    }

    sort(intArr.begin(), intArr.end());
string answer = to_string(intArr.front()) + " " + to_string(intArr.back());
return answer;
}