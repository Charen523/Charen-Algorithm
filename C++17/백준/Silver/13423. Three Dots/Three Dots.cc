#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countArithmeticTriplets(vector<int>& arr) {
	int n = arr.size();
	int count = 0;

	for (int i = 0; i < n - 2; i++) {      // 첫 번째 수 선택
		for (int j = i + 1; j < n - 1; j++) {  // 두 번째 수 선택
			int diff = arr[j] - arr[i];       // 공차 계산
			int expectedThird = arr[j] + diff; // 세 번째 수 예상값 계산

			// 세 번째 수가 배열에 있는지 확인
			if (binary_search(arr.begin() + j + 1, arr.end(), expectedThird)) {
				count++;
			}
		}
	}

	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		vector<int> vec(n);
		for (int j = 0; j < n; j++) {
			cin >> vec[j];
		}
		sort(vec.begin(), vec.end());
		cout << countArithmeticTriplets(vec) << '\n';

	}
}