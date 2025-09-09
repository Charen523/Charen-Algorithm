#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int T; cin >> T; 
	for (int i = 0; i < T; i++) {
		int k; cin >> k; 

		multiset<int> d;
		
		for (int j = 0; j < k; j++) {
			char c; int n;
			cin >> c >> n;

			if (c == 'D') {
				if (d.empty()) continue;
				if (n == -1) {
					d.erase(d.begin());
				}
				else if (n == 1) {
					d.erase(prev(d.end()));
				}
			}
			else if (c == 'I') {
				d.insert(n);
			}
		}
		
		if (d.empty()) {
			cout << "EMPTY";
		}
		else{
			cout << *prev(d.end()) << ' ' << *d.begin();
		}
		cout << '\n';
	}

	return 0;
}