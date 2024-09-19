#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string word;
	cin >> word;

	int length = 10;
	for (size_t i = 0; i < word.size(); i += length) {
		cout << word.substr(i, length) << endl;
	}
}