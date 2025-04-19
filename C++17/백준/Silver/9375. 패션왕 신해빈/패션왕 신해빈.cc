#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		unordered_map<string, int> clothes;
		for (int i = 0; i < n; i++) {
			string name, type;
			cin >> name >> type;
			clothes[type]++;
		}

		int answer = 1;
		for (auto& [type, count] : clothes) {
			answer *= (count + 1);
		}
		cout << answer - 1 << '\n';
	}

	return 0;
}