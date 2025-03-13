#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int lis(const vector<pair<int, int>>& v) {
	vector<int> lis;

	for (pair<int, int> pair : v) {
		int num = pair.second;
		auto it = lower_bound(lis.begin(), lis.end(), num);
		if (it == lis.end())
			lis.push_back(num);
		else *it = num;
	}

	return lis.size();
}

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	//전기줄 개수
	int n; 
	cin >> n;
	
	//연결된 전선의 위치
	vector<pair<int, int>> lines(n);
	for (int i = 0; i < n; i++) {
		cin >> lines[i].first >> lines[i].second;
	}

	sort(lines.begin(), lines.end(), [](pair<int, int> a, pair<int, int> b){
		if (a.first == b.first) {
			return a.second < b.second;
		}
		return a.first < b.first;	
	});

	cout << n - lis(lines);

	return 0;
}