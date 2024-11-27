#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int p, n;
	cin >> p >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (p < 200) {
			k++;
			p += a[i];
		}
		else break;
	}
	cout << k;
}