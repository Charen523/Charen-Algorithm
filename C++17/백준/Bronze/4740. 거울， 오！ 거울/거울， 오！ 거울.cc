#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	while (getline(cin, str)) {
		if (str == "***") break;
		reverse(str.begin(), str.end());
		cout << str << '\n';
	}
}