#include <iostream>
#include <string>

using namespace std;

int main() {
	int charCount, postitCount;
	cin >> charCount >> postitCount;

	string password;
	cin >> password;

	cout << boolalpha;

	for (int i = 0; i < postitCount; i++) {
		string postit;
		cin >> postit;

		bool result = false;
		int pwIdx = 0;
		for (int j = 0; j < postit.length(); j++) {
			if ( postit[j] == password[pwIdx]) {
				pwIdx++;

				if (pwIdx == charCount) {
					result = true;
					break;
				}
					
			}
		}
		cout << result << '\n';
	}
}