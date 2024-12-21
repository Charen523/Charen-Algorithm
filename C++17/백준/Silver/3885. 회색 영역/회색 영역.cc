#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count, width;
	const double defaultInk = 0.01;
	const double widthInk = 0.1;

	while (cin >> count >> width) {
		if (count == 0 && width == 0)
			break;

		vector<int> histoGraph;
		double maxHeight = 0;
		double maxDensity = 0;
		double result = defaultInk;

		for (int i = 0; i < count; i++) {
			int value, segment;

			cin >> value; //입력받은 값
			segment = value / width; //값이 해당하는 x값.
			
			if (histoGraph.size() < segment + 1)
				histoGraph.resize(segment + 1, 0);

			histoGraph[segment]++;

			if (maxHeight < histoGraph[segment])
				maxHeight = histoGraph[segment]; //최대 높이 갱신
		}
		maxDensity = histoGraph.size() - 1;

		for (int i = 0; i < histoGraph.size(); i++) {
			double height = histoGraph[i] / maxHeight;
			double density = (maxDensity - i) / maxDensity;

			result += height * density;
		}

		cout << setprecision(6) << result << '\n';
	}
}