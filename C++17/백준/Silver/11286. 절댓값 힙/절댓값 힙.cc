#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

bool cmp(const int& a, const int& b) {
	if (abs(a) == abs(b)) {
		return a > b;
	}
	return abs(a) > abs(b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	priority_queue<int, vector<int>, bool(*)(const int&, const int&)> pq(cmp);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << 0;
			}
			else {
				cout << pq.top();
				pq.pop();	
			}
			
			cout <<'\n';
			continue;
		}
		pq.push(x);
	}

	return 0;
}