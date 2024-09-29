#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int row, column
		;
	cin >> row >> column;

	int block = 0;

	vector<string> v(row);

	for (int i = 0; i < row; i++) {
		string value;
		cin >> value;
		v[i] = value;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (v[i][j] == '-') {
				block++;
				while (++j < column) {
					if (v[i][j] != '-') break;
				}
			}
		}
	}
	
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			if (v[j][i] == '|') {
				block++;
				while (++j < row) {
					if (v[j][i] != '|') break;
				}
			}
		}
	}

	cout << block << '\n';
}