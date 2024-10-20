#include <iostream>

using namespace std;

int main() {
	string input;
	cin >> input;

	int changeCount = 0;
	for (int i = 1; i < input.size(); i++) {
		if (input[i - 1] != input[i]) {
			changeCount++;
		}
	}

	cout << (changeCount + 1) / 2;
}