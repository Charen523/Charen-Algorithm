#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> alphabetPool;
vector<char> cases;

bool is_vowel(char c) {
	switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		default:
		 	return false;
	}
}

bool is_valid() {
	int a = 0, b = 0;
	for (int i = 0; i < l; i++) {
		if (is_vowel(cases[i])) a++;
		else b++;
	}

	if (a >= 1 && b >= 2) return true;
	else return false;
}

void back_tracking(int idx) {
	if (cases.size() == l && is_valid()) {
		for (int i = 0; i < l; i++) {
			cout << cases[i];
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < c; i++) {
		cases.push_back(alphabetPool[i]);
		back_tracking(i + 1);
		cases.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> l >> c;

	alphabetPool.resize(c);
	for (int i = 0; i < c; i++) {
		cin >> alphabetPool[i];
	}
	sort(alphabetPool.begin(), alphabetPool.end());
	back_tracking(0);

	return 0;
}