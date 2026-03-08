#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isKnight(string a, string b) {
    bool isOne = false; bool isTwo = false;
    char a1 = a[0], b1 = b[0];
    char a2 = a[1], b2 = b[1];
    
    int x = abs(a1 - b1);

    if (x == 1) isOne = true;
    else if (x == 2) isTwo = true;
    else return false;

    int y = abs(a2 - b2);
    if (!isOne && y == 1) return true;
    else if (!isTwo && y == 2) return true;
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size = 36;
    bool result = true;
    
    unordered_set<string> inputs;
    string temp, next; cin >> temp;
    string first = temp;
    inputs.insert(temp);

    for (int i = 1; i < size; i++) {
        cin >> next;
        if (!result) continue;
        if (inputs.count(next)) {
            result = false;
            continue;
        }
        inputs.insert(next);

        if (!isKnight(temp, next)) {
            result = false;
            continue;
        }
        temp = next;
    }

    if (!isKnight(first, temp)) result = false;

    if (result) cout << "Valid";
    else cout << "Invalid";

	// 코드 작성
	return 0;
}