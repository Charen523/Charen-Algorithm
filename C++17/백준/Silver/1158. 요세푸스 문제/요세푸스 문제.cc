#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> answer;
    list<int> l;
    for (int i = 1; i <= n; i++) {
        l.push_back((i));
    }

    auto it = l.begin();
    advance(it, k - 1);
    
    while (!l.empty()) {
        answer.push_back(*it);

        it = l.erase(it);
        if (l.empty()) break;      
        if (it == l.end()) it = l.begin();

        for (int i = 0; i < k - 1; i++){
            it++;
            if (it == l.end()) it = l.begin();
        }
    }
	
    cout << "<";
    for (int i = 0; i < n - 1; i++) {
        cout << answer[i] << ", ";
    }
    cout << answer[n - 1] << ">";
	return 0;
}