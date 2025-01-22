#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> t, p;
vector<int> results;

void dp(int& profit, int today = 0) {
	for (int i = today; i < n; i++) {
		int time = t[i] - 1; int pay = p[i];
		
		//은퇴 전.
		if (i + time < n) {
			//현재 날짜 더하기.
			i += time;
			profit += pay;
			dp(profit, i + 1); //이후 일정 세팅.
			
			//이 날짜 빼고 다른 날짜 더하기.
			i -= time;
			profit -= pay;
		}
	}	

	int result = profit;
	results.push_back(result);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	t.resize(n); p.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}

	int profit = 0;
	dp(profit);
	sort(results.begin(), results.end());
	cout << results[results.size() - 1];
}