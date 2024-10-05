#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double w, h;
	cin >> w >> h;
	double result = w * h / 2;
	cout << fixed << setprecision(1) << result;
}