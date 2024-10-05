#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double a, b;
	while (cin >> a >> b) {
		if (a == 0) {
			if (b == 0) {
				cout << "AXIS"; 
				break;
			}
			else 
				cout << "AXIS" << '\n';
		}
		else if (b == 0) {
			cout << "AXIS" << '\n';
		}
		else if (a > 0) {
			if (b > 0)
				cout << "Q1" << '\n';
			else
				cout << "Q4" << '\n';
		}
		else {
			if (b > 0) {
				cout << "Q2" << '\n';
			}
			else {
				cout << "Q3" << '\n';
			}
		}
	}
}