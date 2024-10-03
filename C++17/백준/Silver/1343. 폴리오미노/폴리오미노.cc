#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	const string block1 = "XXXX";
	const string block2 = "XX";
	const string block3 = "X";
	const string poly1 = "AAAA";
	const string poly2 = "BB";

	string result;
	cin >> result;

	size_t pos = result.find(block1);
	while (pos != string::npos) {
		result.replace(pos, block1.length(), poly1);
		pos = result.find(block1);
	}
	pos = result.find(block2);
	while (pos != string::npos) {
		result.replace(pos, block2.length(), poly2);
		pos = result.find(block2);
	}
	pos = result.find(block3);
	if (pos == string::npos) cout << result;
	else cout << -1;
}