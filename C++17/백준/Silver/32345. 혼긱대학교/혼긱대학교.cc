#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--) {
		string input; cin >> input; 
		long long result = 1;
		int ptr = -1;
		
		for (int i = 0; i < input.size(); i++) {
			if (string("aeiou").find(input[i]) == -1) continue;
			if (ptr != -1) result = 1LL * result * (i - ptr) % mod;
			ptr = i;
		}
		
		result = (ptr == -1) ? -1 : result;
		cout << result << '\n';
	}
}