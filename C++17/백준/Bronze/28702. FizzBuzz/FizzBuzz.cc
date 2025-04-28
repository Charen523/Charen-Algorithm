#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isNumber(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

string translater(int i) {
	bool is3 = i % 3 == 0;
	bool is5 = i % 5 == 0;

	if (is3 && is5) return "FizzBuzz";
	if (is3) return "Fizz";
	if (is5) return "Buzz";
	return to_string(i);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b, c;
	cin >> a >> b >> c;

	try {
		cout << translater(stoi(a) + 3);
	}
	catch (exception) {
		try {
			cout << translater(stoi(b) + 2);
		}
		catch (exception) {
			cout << translater(stoi(c) + 1);
		}
		
	}


	return 0;
}