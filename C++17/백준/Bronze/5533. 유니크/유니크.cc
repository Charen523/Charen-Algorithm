#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    const int rounds = 3;
    int players;
    cin >> players;

    vector<vector<int>> games(players, vector<int>(rounds));

    for (int i = 0; i < players; i++) {
        for (int j = 0; j < rounds; j++) {
            cin >> games[i][j];
        }
    }

    vector<int> scores(players, 0);
    for (int round = 0; round < 3; round++) {
        map<int, int> count; //적은 숫자, 횟수.

        for (int i = 0; i < players; i++) count[games[i][round]]++;

        for (int i = 0; i < players; i++) {
            if (count[games[i][round]] == 1) scores[i] += games[i][round];
        }
    }

    for (int i = 0; i < players; i++) {
        cout << scores[i] << '\n';
    }
}