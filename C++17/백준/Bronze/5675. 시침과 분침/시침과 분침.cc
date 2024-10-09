#include <iostream>

using namespace std;

int main() {
	int input;
	
	while (cin >> input) {
		if (input % 6 == 0)
			cout << "Y\n";
		else
			cout << "N\n";
	}
}