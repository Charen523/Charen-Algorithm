#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	bool numSet[21] = { false };
	for (int i = 0; i < count; i++) {
		string word;
		int value = 0;
		cin >> word;

		if (word[1] == 'l') {
			for (int j = 1; j < 21; j++) {
				numSet[j] = true;
			}
		}
		else if (word[1] == 'm') {
			for (int j = 1; j < 21; j++) {
				numSet[j] = false;
			}
		}
		else {
			cin >> value;

			if (word[1] == 'd') {
				numSet[value] = true;
			}
			else if (word[1] == 'e') {
				numSet[value] = false;
			}
			else if (word[1] == 'h') {
				cout << (int)numSet[value] << '\n';
			}
			else if (word[1] == 'o') {
				numSet[value] = !numSet[value];
			}
		}
	}
}