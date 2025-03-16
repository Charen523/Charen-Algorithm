#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	

	int n, k; //n : 물품의 수, k : 버틸 수 있는 무게.
	cin >> n >> k;

	vector<pair<int, int>> stuff(n); //weight - value.
	for (int i = 0; i < n; i++) {
		cin >> stuff[i].first >> stuff[i].second;
	}

	sort(stuff.begin(), stuff.end(), [](pair<int, int> a, pair<int, int> b){
		if (a.first != b.first) {
			return a.first < b.first;
		}
		else {
			return a.second < b.second;
		}
	});
	
	vector<int> dp(k + 1, 0); //무게별 최대 가치.
	for (int i = 0; i < n; i++) {
		int weight = stuff[i].first, value = stuff[i].second;

		for (int w = k; w >= weight; w--) {
			dp[w] = max(dp[w], dp[w - weight] + value);
		}
	}

	cout << dp[k];
	return 0;
}