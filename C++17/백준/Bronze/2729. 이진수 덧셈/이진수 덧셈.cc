#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string beatCalculater(string a, string b) {
	string result = "";
	int carry = 0;
	int lenA = a.length(), lenB = b.length();
	int i = lenA - 1, j = lenB - 1;

	while (i >= 0 || j >= 0 || carry) {
		int bitA = (i >= 0) ? a[i] - '0' : 0;
		int bitB = (j >= 0) ? b[j] - '0' : 0;
		int sum = bitA + bitB + carry;

		result += (sum % 2) + '0';
		carry = sum / 2;

		i--;
		j--;
	}
	
	reverse(result.begin(), result.end());

	size_t nonZero = result.find_first_not_of('0');
	if (nonZero != string::npos) {
		return result.substr(nonZero); 
	}
	return "0";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		string a, b;
		cin >> a >> b;
		cout << beatCalculater(a, b) << '\n';
	}
}