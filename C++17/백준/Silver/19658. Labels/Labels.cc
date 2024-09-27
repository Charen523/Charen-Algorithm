#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	vector<int> v; 
	v.reserve(count);
	int sum = 1;

	for (int i = 0; i < count; i++) {
		if (i == 0) {
			v.push_back(1);
			continue;
		}

		int value;
		cin >> value;
		sum += value;

		v.push_back(sum);
	}

	int min = v[0]; int max = v[0];
	for (int i = 1; i < count; i++) {
		if (min > v[i]) {
			min = v[i]; continue;
		}
		if (max < v[i]) {
			max = v[i];
		}
	}

	if ((max - min) == count - 1) {
		if (min != v[0]) {
			for (int num : v) {
				num += (1 - min);
				cout << num << ' ';
			}
		}
		else {
			for (int num : v) {
				cout << num << ' ';
			}
		}

		cout << '\n';
	}
	else {
		cout << -1 << '\n';
	}
}