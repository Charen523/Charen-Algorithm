#include <iostream>
#include <cstring>
using namespace std;

int recursionCount;

int recursion(const char* s, int l, int r) {
    recursionCount++;

    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n; 
    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        recursionCount = 0;

        cin >> input;
        cout << isPalindrome(input.c_str()) << ' ';
        cout << recursionCount << '\n';
    }
    return 0;
}