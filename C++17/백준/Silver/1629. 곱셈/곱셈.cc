#include <iostream>
#define ull unsigned long long

using namespace std;

ull modExp(ull a, ull b, ull c) {
	ull result = 1;
	a = a % c;

	while (b > 0) {
		if (b % 2 == 1) {
			result = (result * a) % c;
		}
		a = (a * a) % c;
		b /= 2; 
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ull a, b, c;
	cin >> a >> b >> c;
	cout << modExp(a, b, c);
}