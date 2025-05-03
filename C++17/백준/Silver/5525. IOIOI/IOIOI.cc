#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	string s; cin >> s;

	int result = 0;
	int counter = 0;
	for (int i = 0; i < m; i++) {
		if (s[i] != 'I')
			continue;
		while (i + 2 < m) {
			if (s[i + 1] == 'O' && s[i + 2] == 'I') {
				i += 2;
				counter++;
			}
			else break;
		}

		if (counter - n >= 0) {
			result += (counter - n + 1);
		}
		counter = 0;
	}

	cout << result;

	return 0;
}