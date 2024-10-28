#include <iostream>
#include <map>
#include <climits> // INT_MIN, INT_MAX

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int weeks;
    cin >> weeks;

    map<string, int> workTimes;
    for (int i = 0; i < weeks; i++) {
        for (int timeline = 0; timeline < 4; timeline++) {
            int curTime = (timeline == 1) ? 6 : (timeline == 3) ? 10 : 4;
            
            for (int day = 0; day < 7; day++) {
                string name;
                cin >> name;
                if (name != "-") {
                    workTimes[name] += curTime;
                }
            }
        }
    }

    if (workTimes.empty()) {
        cout << "Yes";
        return 0;
    }

    int maxTime = INT_MIN, minTime = INT_MAX;
    for (const auto& [name, time] : workTimes) {
        maxTime = max(maxTime, time);
        minTime = min(minTime, time);
    }

    cout << ((maxTime - minTime > 12) ? "No" : "Yes");
}
