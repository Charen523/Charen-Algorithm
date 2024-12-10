#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>

using namespace std;

unordered_set<int> primes;

bool isPrime(int num) {
	if (num <= 1) return false;
	if (primes.find(num) != primes.end()) return true;
	if (num % 2 == 0 || num % 3 == 0) return false;

	for (int i = 5; i * i <= num; i += 2) {
		if (num % i == 0) return false;
	}
	primes.insert(num);
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	primes.insert(2);
	primes.insert(3);

	int result = 0;
	for (int i = 2; i <= n; i++) { //수열의 길이
		if (isPrime(i)) {
			for (int j = 0; j <= n - i; j++) {
				int merge = 0;
				for (int k = 0; k < i; k++) {
					merge += arr[j + k];
				}

				if (isPrime(merge)) result++;
			}
		}
	}
	cout << result;
}