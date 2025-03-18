#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	deque<int> arr;
	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
	}

	int result = 0;
	for (int i = 0; i < m; i++) {
		int input; cin >> input;

		auto idx = find(arr.begin(), arr.end(), input);
		if (idx != arr.begin()) {
			if(idx - arr.begin() < arr.end() - idx) {
				result += idx - arr.begin();
				
			}	
			else {
				result += arr.end() - idx;
			}
			rotate(arr.begin(), idx, arr.end());
		}
		
		arr.pop_front();
	}
	cout << result;
    
	return 0;
}