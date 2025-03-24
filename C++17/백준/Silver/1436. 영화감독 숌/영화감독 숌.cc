#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int n; cin >> n;
	int i = 666;
	while (true) {
		string target = to_string(i);
		if (target.find("666") != string::npos) {
			n--;
			if (n == 0) {
				cout << i;
				return 0;
			}
		}
		i++;
	}
}