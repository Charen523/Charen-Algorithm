#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_set<string> input_set;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        input_set.insert(s);
    }

    int count = 0;

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;

        if (input_set.find(s) != input_set.end()) {
            count++;
        }
    }

    cout << count;
    return 0;
}