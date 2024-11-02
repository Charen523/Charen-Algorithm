#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string testCase;
	cin >> testCase;

	int result = 0;
	for (int i = 1; i <= testCase.length(); i++) {
		vector<string> v;

		for (int j = 0; j <= testCase.length() - i; j++) {
			v.push_back(testCase.substr(j, i));
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		result += v.size();
	}

	cout << result;
}