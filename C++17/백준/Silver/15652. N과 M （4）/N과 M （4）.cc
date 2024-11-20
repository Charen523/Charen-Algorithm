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

	for (int i = 1; i <= N; i++) {
		if (!(combination.size() == 0 ||
			combination.size() > 0 && i >= combination.back())) {
			continue;
		}
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