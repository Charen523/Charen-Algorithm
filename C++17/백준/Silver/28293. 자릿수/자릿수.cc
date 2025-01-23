#include <iostream>
#include <cmath>
#define ull unsigned long long 

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ull a, b; 
	cin >> a >> b;

	double log = b * log10(a);
	ull length = (ull)floor(log) + 1;
	cout << length;
}