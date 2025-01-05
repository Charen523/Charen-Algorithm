#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
vector<int> combination;
vector<int> initArr;


struct VectorCompare {
	bool operator()(const vector<int>& a, const vector<int>& b) const {
		return a < b;
	}
};
set<vector<int>, VectorCompare> resultSet;

void makeVecs(vector<bool>& visitedArr) {
	if (combination.size() == m) {
		resultSet.emplace(combination);
		return;
	}

	for (int i = 0; i < initArr.size(); i++) {
		if (!visitedArr[i]) {
			visitedArr[i] = true;
			combination.push_back(initArr[i]);

			makeVecs(visitedArr);
			
			combination.pop_back();
			visitedArr[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	initArr.resize(n);
	vector<bool> visitedArr(n, false);

	for (int i = 0; i < n; i++) {
		cin >> initArr[i];
	}

	sort(initArr.begin(), initArr.end());
	makeVecs(visitedArr);

	for (auto vec : resultSet) {
		for (int i : vec) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}