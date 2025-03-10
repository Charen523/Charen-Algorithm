#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int definedDivider = 1000000000;

int solve(int n) {
	int result = 0;
	if (n == 1) return 9;

	vector<int> lastNumber(10, 1);
	vector<int> nextLast(10, 0);
	lastNumber[0] = 0;

	for (int i = 1; i < n; i++) {
		for (int i = 0; i < 10; i++) {
			if (i > 0) {
				nextLast[i - 1] = (nextLast[i - 1] + lastNumber[i]) % definedDivider;

			}
			if (i < 9) {
				nextLast[i + 1] = (nextLast[i + 1] + lastNumber[i]) % definedDivider;

			}
		}
		lastNumber.swap(nextLast);
		fill(nextLast.begin(), nextLast.end(), 0);
	}

	for (int i = 0; i < 10; i++) {
		result = (result + lastNumber[i]) % definedDivider;
	}

	return result;
}

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int n; 
	cin >> n;
	cout << solve(n);

	return 0;
}