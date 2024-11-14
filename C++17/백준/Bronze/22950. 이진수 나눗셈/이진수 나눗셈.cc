#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	string M;
	cin >> N >> M >> K;

	int min = (N - K > 0)? N - K : 0;
	bool isDivided = true;

	for (int i = min; i < N; i++) {
		if (M[i] == '1') {
			isDivided = false;
			break;
		}
	}
	if (isDivided) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}