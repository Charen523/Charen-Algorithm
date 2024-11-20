#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> combination;
void solve(int start) {
	if (combination.size() == M) {
		for (int c : combination) {
			cout << c << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= N; i++) {
		combination.push_back(i);
		solve(i);
		combination.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	solve(1);
}