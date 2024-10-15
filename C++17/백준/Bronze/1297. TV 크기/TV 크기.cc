#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double D, H, W;
	cin >> D >> H >> W;

	double coef = sqrt(D * D / (W * W + H * H));
	double height = coef * H;
	double width = coef * W;
	cout << floor(height) << ' ' << floor(width);
}