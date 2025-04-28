#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string> pwMap;
	for (int i = 0; i < n; i++) {
		string addr, pw;
		cin >> addr >> pw;
		pwMap[addr] = pw;
	}

	for (int i = 0; i < m; i++) {
		string addr;
		cin >> addr;
		cout << pwMap[addr] << '\n';
	}

	return 0;
}