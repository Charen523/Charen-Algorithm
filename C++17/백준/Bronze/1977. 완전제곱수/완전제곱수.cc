#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int m, n;
	cin >> m >> n;
    
	int min = -1, sum = 0;
	for (int i = m;  i <= n; i++) {
		int root = sqrt(i);
		if (root * root == i) {
			if (min == -1) {
				min = i;
			}

			sum += i;
		}
	}

	if (min == -1) cout << -1;
	else {
		cout << sum << '\n' << min << '\n';
	}

	return 0;
}