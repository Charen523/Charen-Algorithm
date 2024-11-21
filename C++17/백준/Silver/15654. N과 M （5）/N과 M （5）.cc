#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> combination;
void Solve(int idx, vector<int>& initArr, vector<bool>& usedArr) {
	if (combination.size() == M) {
		for (int c : combination) {
			cout << initArr[c] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < N; i++) {
		if (usedArr[i]) continue;
		combination.push_back(i);
		usedArr[i] = true;
		
		Solve(idx, initArr, usedArr);

		combination.pop_back();
		usedArr[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	vector<int> initArr(N);
	for (int i = 0; i < N; i++) {
		cin >> initArr[i];
	}
	sort(initArr.begin(), initArr.end());
	vector<bool> boolArr(N, false);
	Solve(0, initArr, boolArr);
}