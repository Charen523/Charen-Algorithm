#include <iostream>

using namespace std;

int a, b, c, d;

double circumference(int x) {
	return max(a * (x - b) * (x - b) + c, d);
}

int main() {
	cin >> a >> b >> c >> d;
	int N;
	cin >> N;

	int result = 0;
	for (int i = 0; i < N; i++) {
		int u, v;
		cin >> u >> v;
		
		if (v < b) continue;

		if (u == circumference(v)) result++;
	}

	cout << result;
}