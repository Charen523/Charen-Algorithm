#include <iostream>
#include <cmath>

using namespace std;

int findRoundSqrt(int B, int N) {
	int curA = 1;
	int tempAn = pow(curA, N);
	int newAn = pow(++curA, N);
	while (abs(tempAn - B) > abs(newAn - B)) {
		tempAn = newAn;
		newAn = pow(++curA, N);
	}
	return --curA;
}

int main() {
	int B, N;
	
	while (cin >> B >> N) {
		if (B == 0 && N == 0)
			break;
		cout << findRoundSqrt(B, N) << '\n';
	}
}