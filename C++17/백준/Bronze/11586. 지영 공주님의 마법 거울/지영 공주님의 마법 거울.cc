#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int lines, mind;
	cin >> lines;
	vector<string> mirror(lines);
	for (int i = 0; i < lines; i++) {
		cin >> mirror[i];
	}
	cin >> mind;

	if (mind == 1) {
		for (int i = 0; i < lines; i++) cout << mirror[i] << '\n';
	}
	else if (mind == 3) {
		for (int i = lines - 1; i >= 0; i--) cout << mirror[i] << '\n';
	}
	else {
		for (int i = 0; i < lines; i++) {
			for (int j = lines - 1; j >= 0; j--) {
				cout << mirror[i][j];
			}
			cout << '\n';
		}
	}
}