#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> inputArr(n);
	for (int i = 0; i < n; i++) {
		cin >> inputArr[i];
	}
	
	long long result = 0;
	long long zero = count(inputArr.begin(), inputArr.end(), 0);
	int one = count(inputArr.begin(), inputArr.end(), 1);
	int others = n - zero - one;

	//mex = 2
	result += zero * one * 2;

	//mex = 1
	result += zero * (n - one - zero);
	result += zero * (zero - 1) / 2;

	cout << result;
}