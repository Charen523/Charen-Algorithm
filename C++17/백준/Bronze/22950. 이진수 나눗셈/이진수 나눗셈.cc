#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	string M;
	cin >> N >> M >> K;

	int start = max(0, N - K);
	bool isDivided = all_of(M.begin() + start, M.end(), [](char c) { return c == '0'; });

	cout << (isDivided ? "YES" : "NO");
}
