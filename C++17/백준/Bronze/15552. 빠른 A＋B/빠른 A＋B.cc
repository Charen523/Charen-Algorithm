#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int T;
	cin >> T;
	int a, b;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
    
	return 0;
}