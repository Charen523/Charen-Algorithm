#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, idx = 0;
    cin >> n;

    stack<int> s;
    string output;
    
    while (n--) {
        int temp;
        cin >> temp;

        while (idx < temp) { // push
            s.push(++idx);
            output += "+\n";
        }

        if (s.top() == temp) { // pop
            s.pop();
            output += "-\n";
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << output;
    return 0;
}