#include <iostream>

using namespace std;

int main() {
	double x1, x2;
	int a, b, c, d, e;
	cin >> x1 >> x2 >> a >> b >> c >> d >> e;

	double part1 = ((double)1 / 3) * a * (x2 * x2 * x2 - x1 * x1 * x1);
	double part2 = ((double)1 / 2) * (b - d) * (x2 * x2 - x1 * x1);
	double part3 = (c - e) * (x2 - x1);

	cout << part1 + part2 + part3;
}