#include <iostream>
#include <vector>
using namespace std;

int n, s;
vector<int> v;
int counts;

void back_tracking(int idx, int sum) {
	if (idx == n) {
		if (sum == s) counts++;
		return;
	}

	// 포함하는 경우
	back_tracking(idx + 1, sum + v[idx]);

	// 포함하지 않는 경우
	back_tracking(idx + 1, sum);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	back_tracking(0, 0);

	// 공집합 제외
	if (s == 0) counts--;

	cout << counts;
	return 0;
}