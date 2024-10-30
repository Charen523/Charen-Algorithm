#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;

    vector<int> input(testCase);
    for (int i = 0; i < testCase; i++) {
        cin >> input[i];
    }

    vector<int> numSet = input;
    sort(numSet.begin(), numSet.end());
    numSet.erase(unique(numSet.begin(), numSet.end()), numSet.end());

    string result;
    for (int i = 0; i < testCase; i++) {
        int index = lower_bound(numSet.begin(), numSet.end(), input[i]) - numSet.begin();
        result += to_string(index) + " ";
    }

    cout << result;
    return 0;
}