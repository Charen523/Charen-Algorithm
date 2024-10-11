#include <iostream>

using namespace std;

int main() {
	int trainCount = 0;
	int max = 0;

	for (int i = 0; i < 4; i++) {
		int in, out;
		cin >> in >> out;
		trainCount -= in;
		trainCount = (trainCount + out < 10000) ? trainCount + out : 10000;
		
		if (max < trainCount) max = trainCount;
	}

	cout << max;
}