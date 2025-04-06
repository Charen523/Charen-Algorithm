#include <iostream>
#include <unordered_set>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	unordered_set<int> arr;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		arr.insert(input);
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int input; cin >> input;
		bool result = (arr.find(input) != arr.end()) ? 1 : 0;
		cout << result << '\n';
	}

	return 0;
}