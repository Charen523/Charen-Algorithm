#include <iostream>
#include <vector>

using namespace std;

//10:23:30 ~ 
int main() {
	int drinkCount;
	cin >> drinkCount;

	double max = 0, sum = 0;
	vector<int> drinks(drinkCount);
	for (int i = 0; i < drinkCount; i++) {
		cin >> drinks[i];
		
		sum += drinks[i];
		if (drinks[i] > max) max = drinks[i];
	}

	cout << sum / 2 + max / 2;
}