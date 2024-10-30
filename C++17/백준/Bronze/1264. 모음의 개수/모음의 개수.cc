#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string line, result = "";
	while (getline(cin, line)) {
		if (line == "#") break;

		int count = 0;
		for (int i = 0; i < line.length(); i++) {
			switch (line[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				count++;
				break;
			}
		}

		result += to_string(count) + '\n';
	}
	cout << result;
}