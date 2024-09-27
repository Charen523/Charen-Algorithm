#include <iostream>

using namespace std;

long long power(int exp) {
	if (exp == 0)
		return 1;

	long long half = power(exp / 2);
	if (exp % 2 == 0)
		return half * half;
	else
		return half * half * 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int size, row, column;
	cin >> size >> row >> column;

	int result = 0;
	int sampleSize = power(size);
	int totalSize = sampleSize * sampleSize;
	int rowOffset = 0, columnOffset = 0;

	for (int i = 0; i < size; i++) {
		totalSize /= 4;
		sampleSize /= 2;

		if (row >= sampleSize + rowOffset) { 
			result += totalSize * 2; 
			rowOffset += sampleSize; 
		}
		if (column >= sampleSize + columnOffset) { 
			result += totalSize; 
			columnOffset += sampleSize; 
		}
	}
	cout << result << '\n';
}