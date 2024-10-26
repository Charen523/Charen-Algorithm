#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static long long cutCount(const vector<int>& trees, int cut) {
	long long result = 0;
	for (int height : trees) {
		if (height > cut) {
			result += height - cut;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	vector<int> trees(N);
	int maxHeight = 0;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
		maxHeight = max(maxHeight, trees[i]);
	}

	int left = 0, right = maxHeight, result = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		long long wood = cutCount(trees, mid);

		if (wood >= M) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << result;
}