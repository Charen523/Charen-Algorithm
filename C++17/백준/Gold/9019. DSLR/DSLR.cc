#include <iostream>
#include <vector>
#include <queue>      
#include <algorithm>  
using namespace std;

inline int D(int x) { return (x * 2) % 10000; }
inline int S(int x) { return x == 0 ? 9999 : x - 1; }
inline int L(int x) { return (x % 1000) * 10 + x / 1000; }
inline int R(int x) { return (x % 10) * 1000 + x / 10; }

void solve(int A, int B) {
    if (A == B) {
        cout << '\n';
        return;
    }

    vector<int> parent(10000, 0);
    vector<char> visited(10000, 0);
    parent[A] = -1;
    visited[A] = ' ';
    queue<int> q; q.push(A);
    char ch[4] = { 'D', 'S', 'L', 'R' };

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        int nxt[4] = { D(num), S(num), L(num), R(num) };
        for (int i = 0; i < 4; i++) {
            int temp = nxt[i];
            if (visited[temp] == 0) {
                visited[temp] = ch[i];
                parent[temp] = num;

                if (temp == B) {
                    string result = "";
                    char cur = visited[temp];
                    while (cur != ' ') {
                        result += cur;
                        temp = parent[temp];
                        cur = visited[temp];
                    }
                    reverse(result.begin(), result.end());
                    cout << result << '\n';
                }
                else q.push(temp);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int A, B; cin >> A >> B;
        solve(A, B);
    }

    return 0;
}