#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> primes = { 2, 3 };

bool is_prime(int num) {
	if (num <= 1) return false;
	
	int sqrtNum = static_cast<int>(std::sqrt(num));
	for (int p : primes) {
		if (p > sqrtNum) break;
		if (num % p == 0) return false;
	}
	return true;
}

int find_prime(int curPrime = 1) {
	if (curPrime <= 1) return 2;

	int result = curPrime + 1;
	if (result % 2 == 0) result++;

	while (true) {
		if (is_prime(result)) {
			primes.push_back(result);
			return result;
		}
		result += 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int div = primes[0];

	while (n > 1) {
		if (n % div == 0) {
			n /= div;
			cout << div << '\n';
		}
		else (div = find_prime(div));
	}
}