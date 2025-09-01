#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string input;
	cin >> input;

	int sum = 0;
	bool isEven = false;
	vector<int> arr(input.length());
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '*') {
			arr[i] = -1;
			isEven = i % 2 != 0;
		}
		else {
			arr[i] = input[i] - '0';
			if (i % 2 != 0) {
				sum += arr[i] * 3;
			}
			else {
				sum += arr[i];
			}
		}
	}

	sum %= 10;
	int result = 10 - sum;
	if (result == 10) result = 0;

	if (isEven) {
		if (result % 3 == 0) {
			result = result / 3;
		}
		else if ((result + 10) % 3 == 0) {
			result = (result + 10) / 3;
		}
		else
			result = (result + 20) / 3;
	}

	cout << result;
	return 0;
}