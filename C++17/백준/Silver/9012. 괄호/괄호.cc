#include <iostream>

using namespace std;

string validResult(string psCase);

int main() {
	int testCount;
	cin >> testCount;

	for (int i = 0; i < testCount; i++) {
		string psCase;
		cin >> psCase;
		cout << validResult(psCase) << endl;
	}
}

string validResult(string psCase) {
	int open = 0;

	for (int i = 0; i < psCase.size(); i++) {
		if (psCase[i] == '(') open++;
		else open--;

		if (open < 0) return "NO";
	}
	if (open == 0) return "YES";
	else return "NO";
}