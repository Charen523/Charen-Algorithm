#include <iostream>
#include <unordered_set>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector <int> K(M);
	for (int i = 0; i < M; i++) {
		cin >> K[i];
	}

	unordered_set<int> multiples;
	for (int i = 1; i <= N / K[0]; i++) {
		for (int k : K) {
			int m = k * i;
			if (m <= N) {
				multiples.insert(m);
			}
		}
	}

	int result = accumulate(multiples.begin(), multiples.end(), 0);
	cout << result;
}