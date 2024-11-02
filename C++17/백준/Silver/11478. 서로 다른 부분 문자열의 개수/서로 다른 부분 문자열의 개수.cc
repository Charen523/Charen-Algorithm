#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string testCase;
	cin >> testCase;

	unordered_set<string> countMember;

	for (int i = 1; i <= testCase.length(); i++) {
		for (int j = 0; j <= testCase.length() - i; j++) {
			countMember.emplace(testCase.substr(j, i));
		}
	}

	cout << countMember.size();
}