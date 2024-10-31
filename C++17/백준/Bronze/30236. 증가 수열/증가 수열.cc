#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase;
	cin >> testCase;
	
	string results;
	for (int i = 0; i < testCase; i++) {
		int n;
		cin >> n;

		int idx_value = 0;
		for (int j = 1; j <= n; j++) {
			int value;
			cin >> value;

			if (value - j == idx_value) {
				idx_value++;
			}
		}
		results += to_string(n + idx_value) + '\n';
	}
	cout << results;
}