#include <iostream>
#define ll long long

using namespace std;

ll combine[31][31];

void preprocess() {
	for (int i = 0; i <= 30; ++i) {
		combine[i][0] = combine[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			combine[i][j] = combine[i - 1][j - 1] + combine[i - 1][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	preprocess();

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int N, M;
		cin >> N >> M;
		cout << combine[M][N] << '\n';
	}
}