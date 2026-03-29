#include <iostream>
#include <vector>
using namespace std;

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
    return { a.first + b.first, a.second + b.second };
}

bool isRanged(const pair<int, int>& p) {
    if (p.first >= 0 
    && p.first < 8
    && p.second >= 0
    && p.second < 8) return true;
    
    return false;
}

pair<int, int> StringToPair(string pos) {
    int row, col;
    row = pos[0] - 'A';
    col = pos[1] - '1';

    pair<int, int> result;
    result.first = row;
    result.second = col;
    
    return result;
}

string PairToString(pair<int, int> pos) {
    char row, col;
    row = pos.first + 'A';
    col = pos.second + '1';

    string result = "  ";
    result[0] = row; 
    result[1] = col;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string kingPos, rockPos;
    int moveCount;
    cin >> kingPos >> rockPos >> moveCount;

    pair<int, int> k, r;
    k = StringToPair(kingPos);
    r = StringToPair(rockPos);

    for (int i = 0; i < moveCount; i++) {
        string input; cin >> input;

        pair<int, int> direction = {0, 0};
        if (input == "R"){
            direction.first += 1;
        }
        else if (input == "L") {
            direction.first -= 1;
        }
        else if (input == "B") {
            direction.second -= 1;
        }
        else if (input == "T") {
            direction.second += 1;   
        }
        else if (input == "RT") {
            direction.first += 1;
            direction.second += 1;   
        }
        else if (input == "LT") {
            direction.first -= 1;
            direction.second += 1;   
        }
        else if (input == "RB") {
            direction.first += 1;
            direction.second -= 1;
        }
        else if (input == "LB") {
            direction.first -= 1;
            direction.second -= 1;
        }

        pair<int, int> newK = k + direction;
        if (isRanged(newK)) {
            if (newK == r) {
                if (!isRanged(r + direction)) {
                    continue;
                }
                else {
                    r = r + direction;
                }
            }
            k = newK;
        }
    }

    kingPos = PairToString(k);
    rockPos = PairToString(r);
    
    cout << kingPos << '\n' << rockPos << '\n';
	return 0;
}