#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string num;
	cin >> num;
	
	int i, max = 10, min = 1, result = 0;
	for (i = 1; i < num.length(); i++) {
		result += i * (max - min);
		max *= 10; min *= 10;
	}
	max = stoi(num) + 1;
	result += i * (max - min);

	cout << result;
}