#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);  // C++ 표준 스트림을 비동기화
	cin.tie(NULL);

	int arrSize, caseSize; 
	cin >> arrSize >> caseSize;

	vector<int> prefixSum(arrSize + 1, 0);

	for (int i = 1; i <= arrSize; i++) {
		int value;
		cin >> value;
		prefixSum[i] = value + prefixSum[i - 1];
	}

	int startIndex, endIndex;
	for (int i = 0; i < caseSize; i++) {
		cin >> startIndex >> endIndex;
		cout << prefixSum[endIndex] - prefixSum[startIndex - 1] << '\n';
	}
}