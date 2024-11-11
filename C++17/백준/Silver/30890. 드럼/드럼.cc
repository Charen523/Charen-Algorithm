#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int left, right;
	cin >> left >> right;

	double curPos = 0;
	double i = 1, j = 1;

	string result = "";
	while (curPos < 1) {
		double l = i / left;
		double r = j / right;

		if (l > r) {
			curPos = r;
			j++;
			result += "2";
		}
		else if (l < r) {
			curPos = l;
			i++;
			result += "1";
		}
		else {
			curPos = l;
			i++; j++;
			result += "3";
		}
	}
	cout << result;
}