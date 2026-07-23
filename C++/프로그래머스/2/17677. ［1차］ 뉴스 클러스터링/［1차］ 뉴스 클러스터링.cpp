#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_upper(string s) {
    const int DELTA = 'a' - 'A';

    for (char& c : s) {
        if (c >= 'a' && c <= 'z') {
            c -= DELTA;
        }
    }

    return s;
}

vector<string> make_set(const string& s) {
    vector<string> result;

    for (int i = 0; i + 1 < s.size(); i++) {
        char first = s[i];
        char second = s[i + 1];

        if (first >= 'A' && first <= 'Z' &&
            second >= 'A' && second <= 'Z') {
            result.push_back(s.substr(i, 2));
        }
    }

    return result;
}

int solution(string str1, string str2) {
    str1 = to_upper(str1);
    str2 = to_upper(str2);

    vector<string> v1 = make_set(str1);
    vector<string> v2 = make_set(str2);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int ptr1 = 0;
    int ptr2 = 0;
    int intersection = 0;

    while (ptr1 < v1.size() && ptr2 < v2.size()) {
        if (v1[ptr1] == v2[ptr2]) {
            intersection++;
            ptr1++;
            ptr2++;
        }
        else if (v1[ptr1] < v2[ptr2]) {
            ptr1++;
        }
        else {
            ptr2++;
        }
    }

    int union_size = v1.size() + v2.size() - intersection;

    if (union_size == 0) {
        return 65536;
    }

    return 65536 * intersection / union_size;
}