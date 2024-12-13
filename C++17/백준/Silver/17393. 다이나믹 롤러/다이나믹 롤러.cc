#include <iostream>
#include <vector>

using namespace std;

vector<long long> a;
vector<long long> b; //오름차순.

long long binarySearch(int idx) {
	int left = idx + 1, right = b.size() - 1;
	long long result = -1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (b[mid] <= a[idx]) { //허용범위
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}

	return (result == -1) ? 0 : result - idx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	b.resize(n);
	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0; i < n; i++) {
		cout << binarySearch(i) << ' ';
	}
}