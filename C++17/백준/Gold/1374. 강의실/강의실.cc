#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int n; 
	cin >> n;

	priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> pq;
	for (int i = 0; i < n; i++) {
		int idx, start, end;
		cin >> idx >> start >> end;
		pq.push({start, true});
		pq.push({end, false});
	}

	int temp = 0, result = 0;
	while (!pq.empty()) {
		int type = pq.top().second;
		pq.pop();

		if (type) temp++;
		else temp--;

		result = max(result, temp);
	}
    
	cout << result;
	return 0;
}