#include <iostream>
#include <string>

using namespace std;

int changer(char c) {
	int decimalNum = (int)c;
	return (decimalNum / 100 + decimalNum % 100 / 10 + decimalNum % 10);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		char curChar = S[i];
		for (int j = 0; j < changer(curChar); j++) {
			cout << curChar;
		}
		cout << '\n';
	}
}