#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	unordered_map<int, int> nums(n);
	for (int i = 0;i < n ; i++) {
		int input; cin >> input;
		if (nums.find(input) == nums.end()) {
			nums[input] = 1;
		}
		else nums[input]++;
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int input; cin >> input;
		if (nums.find(input) == nums.end())
			cout << 0 << ' ';
		else 
			cout << nums[input] << ' ';
	}

	return 0;
}