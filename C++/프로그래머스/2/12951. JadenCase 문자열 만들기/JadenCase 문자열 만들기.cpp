#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    bool isFirst = true;

    for (char& c : s) {
        if (c == ' ') {
            isFirst = true;
            continue;
        }

        if (isFirst) {
            if ('a' <= c && c <= 'z') c -= 32;
            isFirst = false;
        } else {
            if ('A' <= c && c <= 'Z') c += 32;
        }
    }

    return s;
}