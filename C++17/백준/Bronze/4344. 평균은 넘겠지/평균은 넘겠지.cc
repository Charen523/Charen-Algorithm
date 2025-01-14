#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip> 

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int n;
		cin >> n;

		vector<int> scores(n);
		for (int j = 0; j < n; j++) {
			cin >> scores[j];
		}
		double average = accumulate(scores.begin(), scores.end(), 0) / n;

		int upperAverage = 0;
		for (int j = 0; j < n; j++) {
			if (average < scores[j]) upperAverage++;
		}

		cout << fixed << setprecision(3) << static_cast<double>(upperAverage) / n * 100 << "%\n";
	}
}