#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;

    vector<tuple<int, int, string>> members(count);
    for (int i = 0; i < count; i++) {
        int age;
        string name;
        cin >> age >> name;

        members[i] = { age, i, name };
    }

    sort(members.begin(), members.end());

    for (const auto& [age, i, name] : members) {
        cout << age << ' ' << name << '\n';
    }
}